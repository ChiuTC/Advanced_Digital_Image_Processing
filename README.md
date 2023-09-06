# Advanced_Digital_Image_Processing  



  
## ADIP_1 result:

### 1.2.a 
#### Read the raw image
![lena256_out_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/cc0ab9b7-6c50-47d4-8c4a-b7af1889774c)
### 1.2.b
#### Read the raw image (opencv)
![lena256out_opencv_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/ed14f09b-a255-4b45-ae63-27f60f4a2c24)
### 1.2.c
#### Rotate the raw image 
![lena_rotate_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/2355babe-a907-473b-98d9-0adb700aff4c)
### 1.2.d
#### Cutting an image horizontally or vertically
![lena_hor_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/3d1ec77b-784f-475c-8d22-25ec3d4ca159)

![lena_ver_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/ebcdaf61-1386-49ee-9b8d-a84fcb948f5a)
### 1.2.e
#### Image stitching
![combine_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/0e0da769-5c00-4418-ba36-c8dde17c15cb)
### 1.3.a
#### Adding value 45 to each pixel value of the image
![lena_add_value45_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/a51fb144-a3c3-4226-9542-9774fc97838e)
### 1.3.b
#### Adding random value between -55 to 55 to each pixel value of the image
![lena_add_randomValue_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/ffbb852a-16de-44f4-89d8-e1e69c110a80)

## ADIP_2 result:
### 2.1.2
### Calculate the MSE and PSNR between blurred image and original image.
#### original image
![lena256_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/bfa0c578-c559-48ba-9de5-9e223e756b1b)
#### blur 50
![lena256_blur_50](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/81a7cd63-a8c9-4df8-b403-2ea09bf4029f)
#### blur 100
![lena256_blur_100](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/2a0fcdee-a7f4-4850-9f52-83268ccfb847)

### 2.2.1
### Use nearest neighbor and bilinear algorithms to resize lena128.raw into 256x256 and 512x512, than calculate the MSE and PSNR.
#### original image
![lena128](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/6100b33d-5ecb-485e-b4e2-d283f4279861)
#### nearest neighbor
![lena128_resize_256_nearest](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/37047c79-63a8-46f8-8085-9c09df366722)
![lena128_resize_256_bilinear](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/15bdfa5d-a1a7-4b3c-9066-f7148be1df91)
#### bilinear
![lena128_resize_512_nearest](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/3a6fd32e-f1be-49c2-b5d4-3ee0681ba58f)
![lena128_resize_512_bilinear](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/db513d41-11d3-4dad-89f5-18756ccde858)

### 2.2.2 
### Use nearest neighbor and bilinear algorithms to resize lena512.raw into 256x256 and 128x128, try to blur the image when scaling down.
#### original image
![lena512_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/81971f13-7f79-4fd2-b4d3-3d4bba10488f)
#### nearest neighbor
![lena512_resize_256_nearest_blur](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/d6ca3142-9e73-4f0b-8607-dc4693dbc732)
![lena512_resize_256_nearest](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/a3e9cffb-b0eb-4587-8244-bce58f62d2f2)
#### bilinear
![lena512_resize_256_bilinear_blur](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/76de3156-cc7c-4617-a6ae-3b8dbaeff7ca)
![lena512_resize_256_bilinear](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/253667dd-bebe-49b5-aca2-ecba604c752c)
#### nearest neighbor
![lena512_resize_128_nearest](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/51c2e296-8e7f-440e-be40-59badeb65788)
#### nearest neighbor (after blur)
![lena512_resize_128_nearest_blur](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/483a6a3e-1b6f-47c0-9285-6d303e297f17)
#### bilinear
![lena512_resize_128_bilinear](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/3da08434-96ce-4768-9f52-e2f9290fba5d)
#### bilinear (after blur)
![lena512_resize_128_bilinear_blur](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/ade2d9db-1787-4354-a7ca-3b83e85cf52d)

### 2.2.3
### Use bilinear and bicubic algorithms to zoom in the part from (177,108) to (276,249) in duck900x600.
#### original image
![duck900x660_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/f4bf7bae-c69d-4824-b912-326b6276e217)
#### bilinear
![duck_zoom_in_bilinear](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/fceb1d2f-4bcc-4a59-99fd-5907ed3b7dae)
#### bicubic
![duck_zoom_in_bicubic](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/7c36d82d-fb47-4136-97ee-441b549e4df0)
### 2.3
### Quantize the gray-level resolution of lena256.raw and baboon256.raw from 8 bits to 1 bits.
![lena8](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/55f79118-4834-421f-af30-a57d9cde58b4)
![lena7](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/a2a43c30-b49e-4c37-b746-51e780978158)
![lena6](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/13a0eab3-f306-4b09-a8e3-2abd6ca3d1ca)
![lena5](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/ec2a5254-65d6-42c7-9589-cd7dc7d5cc2b)
![lena4](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/ef3e1b9f-7315-497d-a9cd-b4efebdc39d4)
![lena3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/a54f934b-0564-4ade-8a58-59ae208033dc)
![lena2](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/99966c5f-9d10-49dd-82b4-14c21d50884e)
![lena1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/91535efd-26f5-40c1-a725-42c5b2a6a27b)  

![baboon8](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/eecd5f78-ceae-48e4-a075-6c53e7e4bec3)
![baboon7](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/73ead11d-6277-4666-9286-615e222d810c)
![baboon6](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/5168c0a4-e5c0-43d9-8437-a25137d5f609)
![baboon5](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/0c59168c-ade8-48dc-a39a-58e62d9d87f9)
![baboon4](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/b8207b6f-9987-48c4-9b71-0ef55a017037)
![baboon3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/6c0a2368-c6a5-4605-aadd-8fcf236705c1)
![baboon2](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/6e80c475-846f-42d5-b23a-71eb9e8bde5c)
![baboon1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/0566246c-bd2b-4fef-b951-8314529238dd)
### 2.4
### Find out the solutions from start (0,14) to end (34,93) using D4, D8 and Dm distance on map100x100.
#### map100x100
![map100x100_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/c8a3dce3-d6f7-4c14-88f7-aa35a6987dde)
####  D4
![map_D4](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/f64f7cc0-d9da-4886-886e-1c985c1c3273) 
#### D8
![map_D8](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/e896bdd4-6bb8-48b2-b47a-caf634fbf63c)
#### Dm
![map_Dm](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/71adaadd-7920-40df-b7d5-ca5fc978c07e)

