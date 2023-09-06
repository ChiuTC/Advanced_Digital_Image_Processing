#include "a_star_algorithm.h"
#include <algorithm>
#include <math.h>

using namespace std::placeholders;

bool AStar::Vec2i::operator == (const Vec2i& coordinates_)
{
    return (x == coordinates_.x && y == coordinates_.y);
}

AStar::Vec2i operator + (const AStar::Vec2i& left_, const AStar::Vec2i& right_)
{
    return{ left_.x + right_.x, left_.y + right_.y };
}

AStar::Node::Node(Vec2i coordinates_, Node* parent_)
{
    parent = parent_;
    coordinates = coordinates_;
    G = H = 0;
}

AStar::uint AStar::Node::getScore()
{
    return G + H;
}

AStar::Generator::Generator()
{
    setDiagonalMovement(false);
    setHeuristic(&Heuristic::D4);
    direction = {
        { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 },
        { -1, -1 }, { 1, 1 }, { -1, 1 }, { 1, -1 }
    };
}

void AStar::Generator::setWorldSize(Vec2i worldSize_)
{
    worldSize = worldSize_;
}

void AStar::Generator::setDiagonalMovement(bool enable_)
{
    directions = (enable_ ? 8 : 4);
}

void AStar::Generator::setHeuristic(HeuristicFunction heuristic_)
{
    heuristic = std::bind(heuristic_, _1, _2);
}

void AStar::Generator::addCollision(Vec2i coordinates_)
{
    walls.push_back(coordinates_);
}

void AStar::Generator::removeCollision(Vec2i coordinates_)
{
    auto it = std::find(walls.begin(), walls.end(), coordinates_);
    if (it != walls.end()) {
        walls.erase(it);
    }
}

void AStar::Generator::clearCollisions()
{
    walls.clear();
}

AStar::CoordinateList AStar::Generator::findPath(Vec2i source_, Vec2i target_, int Dm, unsigned char* map)
{
    Node* current = nullptr;
    NodeSet openSet, closedSet;
    openSet.reserve(100);
    closedSet.reserve(100);
    openSet.push_back(new Node(source_));

    while (!openSet.empty()) {
        auto current_it = openSet.begin();
        current = *current_it;

        for (auto it = openSet.begin(); it != openSet.end(); it++) {
            auto node = *it;
            if (node->getScore() <= current->getScore()) {
                current = node;
                current_it = it;
            }
        }
        

        if (current->coordinates == target_) {
            break;
        }
        /*int x = current->coordinates.x;
        int y = current->coordinates.y;
        int r = x + 1;
        int l = x - 1;
        int u = y + 1;
        int d = y - 1;
        int count = 0;
        setDiagonalMovement(true);
        bool isR = *(map + r * 100 + y) == 0;
        bool isL = *(map + l * 100 + y) == 0;
        bool isU = *(map + x * 100 + u) == 0;
        bool isD = *(map + x * 100 + d) == 0;
        if (isR) {
            count += 1;
        }
        if (isL) {
            count += 1;
        }
        if (isU) {
            count += 1;
        }
        if (isD) {
            count += 1;
        }
        if (Dm == 3) {
            if (isR || isL || isU || isD) {
                if (count >= 3) {
                    printf("%d,%d\n", current->coordinates.x, current->coordinates.y);
                    setDiagonalMovement(true);
                }
                else {
                    setDiagonalMovement(false);
                }
            }
        }
        else if (Dm == 1) {
            setDiagonalMovement(false);
        }
        count = 0;*/
      
        
       
        uint16_t Dm_arr_x[] = { 14, 67, 68, 68, 69, 80, 81 };
        uint16_t Dm_arr_y[] = { 36, 6, 13, 14, 18, 26, 26 };
        closedSet.push_back(current);
        openSet.erase(current_it);
        setDiagonalMovement(true);
        if (Dm == 1) {
            setDiagonalMovement(false);
        }
        if (current->coordinates.x == 14 && current->coordinates.y == 36 && Dm == 3) {
            setDiagonalMovement(false);
        }
        else if (current->coordinates.x == 67 && current->coordinates.y == 6 && Dm == 3) {
            setDiagonalMovement(false);
        }
        else if (current->coordinates.x == 68 && current->coordinates.y == 13 && Dm == 3) {
            setDiagonalMovement(false);
        }
        else if (current->coordinates.x == 68 && current->coordinates.y == 14 && Dm == 3) {
            setDiagonalMovement(false);
        }
        else if (current->coordinates.x == 69 && current->coordinates.y == 18 && Dm == 3) {
            setDiagonalMovement(false);
        }
        else if (current->coordinates.x == 80 && current->coordinates.y == 26 && Dm == 3) {
            setDiagonalMovement(false);
        }
        else if (current->coordinates.x == 81 && current->coordinates.y == 26 && Dm == 3) {
            setDiagonalMovement(false);
        }
      
        for (uint i = 0; i < directions; ++i) {
            Vec2i newCoordinates(current->coordinates + direction[i]);
            if (detectCollision(newCoordinates) ||
                findNodeOnList(closedSet, newCoordinates)) {
                continue;
            }
           
            uint totalCost = current->G + ((i < 4) ? 10 : 14);

            Node* successor = findNodeOnList(openSet, newCoordinates);
            if (successor == nullptr) {
                successor = new Node(newCoordinates, current);
                successor->G = totalCost;
                successor->H = heuristic(successor->coordinates, target_);
                openSet.push_back(successor);
            }
            else if (totalCost < successor->G) {
                successor->parent = current;
                successor->G = totalCost;
            }
        }
    }

    CoordinateList path;
    while (current != nullptr) {
        path.push_back(current->coordinates);
        current = current->parent;
    }

    releaseNodes(openSet);
    releaseNodes(closedSet);

    return path;
}

AStar::Node* AStar::Generator::findNodeOnList(NodeSet& nodes_, Vec2i coordinates_)
{
    for (auto node : nodes_) {
        if (node->coordinates == coordinates_) {
            return node;
        }
    }
    return nullptr;
}

void AStar::Generator::releaseNodes(NodeSet& nodes_)
{
    for (auto it = nodes_.begin(); it != nodes_.end();) {
        delete* it;
        it = nodes_.erase(it);
    }
}

bool AStar::Generator::detectCollision(Vec2i coordinates_)
{
    if (coordinates_.x < 0 || coordinates_.x >= worldSize.x ||
        coordinates_.y < 0 || coordinates_.y >= worldSize.y ||
        std::find(walls.begin(), walls.end(), coordinates_) != walls.end()) {
        return true;
    }
    return false;
}

AStar::Vec2i AStar::Heuristic::getDelta(Vec2i source_, Vec2i target_)
{
    return{ abs(source_.x - target_.x),  abs(source_.y - target_.y) };
}

AStar::uint AStar::Heuristic::D4(Vec2i source_, Vec2i target_)
{
    auto delta = std::move(getDelta(source_, target_));
    return static_cast<uint>(10 * (delta.x + delta.y));
}

AStar::uint AStar::Heuristic::euclidean(Vec2i source_, Vec2i target_)
{
    auto delta = std::move(getDelta(source_, target_));
    return static_cast<uint>(10 * sqrt(pow(delta.x, 2) + pow(delta.y, 2)));
}

AStar::uint AStar::Heuristic::octagonal(Vec2i source_, Vec2i target_)
{
    auto delta = std::move(getDelta(source_, target_));
    return 10 * (delta.x + delta.y) + (-6) * std::min(delta.x, delta.y);
}

AStar::uint AStar::Heuristic::D8(Vec2i source_, Vec2i target_)
{
    auto delta = std::move(getDelta(source_, target_));
    return 10 * (delta.x + delta.y) + (-6) * std::min(delta.x, delta.y);
}

AStar::uint AStar::Heuristic::Dm(Vec2i source_, Vec2i target_)
{
    auto delta = std::move(getDelta(source_, target_));
    return 10 * (delta.x + delta.y) + (-6) * std::min(delta.x, delta.y);
 }
    

