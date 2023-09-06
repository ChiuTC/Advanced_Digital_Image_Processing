# Advanced Digital Image Processing   
The implementation code for the assignment in the image processing algorithm course, and the resulting image is shown below.  
Development Environment:  
Visual Studio 2022  
OpenCV version: 4.6.0 (Most of the code does't use OpenCV, only use c/c++ to implement the algorithms)
## ADIP_1 result:

### 1.2.a 
#### Read the raw image
![lena256_out_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/49395e91-be19-4eae-83fa-64c786120ceb)
### 1.2.b
#### Read the raw image (opencv)
![lena256out_opencv_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/b2c4c4cc-f7e8-41f1-bdf6-4c57f3b8edcc)
### 1.2.c
#### Rotate the raw image 
![lena_rotate_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/e81f47c1-5873-4ae4-96e2-7bce021a1e0c)
### 1.2.d
#### Cutting an image horizontally or vertically
![lena_hor_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/0247d6a1-be27-43e8-b517-7702c5037edb)
![lena_ver_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/dd4d8538-5cc8-48e5-a9f0-a044f88e4907)
### 1.2.e
#### Image stitching
![combine_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/ad49a991-c1ea-4d75-8e35-87c3b467226d)
### 1.3.a
#### Adding value 45 to each pixel value of the image
![lena_add_value45_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/55313cea-604d-4702-9d94-e23fb8f3e5c1)
### 1.3.b
#### Adding random value between -55 to 55 to each pixel value of the image
![lena_add_randomValue_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/e93e7a33-5095-4386-be47-d536d9d103dd)


## ADIP_2 result:
### 2.1.2
### Calculate the MSE and PSNR between blurred image and original image.
#### original image
![lena256_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/da610e58-112c-40a1-b43e-a381523ebe72)
#### blur 50
![lena256_blur_50](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/7b66879a-0bc0-4367-9115-ecb06d068ec8)
#### blur 100
![lena256_blur_100](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/b2734185-5c1d-4183-9b8b-85de7f4db4f8)

### 2.2.1
### Use nearest neighbor and bilinear algorithms to resize lena128.raw into 256x256 and 512x512, than calculate the MSE and PSNR.
#### original image
![lena128](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/349aa722-1bc0-4796-a67a-215a97ed9bf2)
#### nearest neighbor 256x256
![lena128_resize_256_nearest](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/3acd0b83-c260-4fbe-a706-18982ee065cd)
#### nearest neighbor 512x512
![lena128_resize_512_nearest](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/24aa3ea3-0bfd-4799-9dc1-b4d1559b86b4)
#### bilinear 256x256
![lena128_resize_256_bilinear](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/8638387e-2192-4514-b941-d45d7db41e1f)
#### bilinear 512x512
![lena128_resize_512_bilinear](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/68c994c5-610e-4e72-ae01-b87eee33cba8)

### 2.2.2 
### Use nearest neighbor and bilinear algorithms to resize lena512.raw into 256x256 and 128x128, try to blur the image when scaling down.
#### original image
![lena512_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/6b44d9b3-0657-4723-813d-b064e2e06bcd)
#### nearest neighbor 256x256 
![lena512_resize_256_nearest](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/c434a73e-d10e-41fa-bc45-693226e4f1ed)
#### nearest neighbor 256x256 (after blur) 
![lena512_resize_256_nearest_blur](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/40875a90-1410-4180-8fc7-ed45e877732d)
#### bilinear 256x256 
![lena512_resize_256_bilinear](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/e5013294-b00a-4d20-848e-b909b2d7016b)
#### bilinear 256x256 (after blur)
![lena512_resize_256_bilinear_blur](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/ff71bfe0-30b2-4172-8c34-0b40c3c252c0)
#### nearest neighbor 128x128
![lena512_resize_128_nearest](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/ead2364b-498c-4f9e-bedd-5b4ac514d769)
#### nearest neighbor 128x128 (after blur)
![lena512_resize_128_nearest_blur](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/ec4481cb-9590-4515-9d75-5202edf77b4a)
#### bilinear 128x128
![lena512_resize_128_bilinear](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/ada97d80-2b97-4487-b8bb-e135ad509206)
#### bilinear 128x128 (after blur)
![lena512_resize_128_bilinear_blur](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/ecf33f0e-126e-47d4-8431-07fefb359746)


### 2.2.3
### Use bilinear and bicubic algorithms to zoom in the part from (177,108) to (276,249) in duck900x600.
#### original image
![duck900x660_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/605a9aae-3362-404e-a02d-a1ad60080328)
#### bilinear
![duck_zoom_in_bilinear](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/eeef9601-8991-4edf-861b-d7fb586ab31b)
#### bicubic
![duck_zoom_in_bicubic](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/9c24ff6a-1f43-4ebd-99cd-7a4ce413eade)
### 2.3
### Quantize the gray-level resolution of lena256.raw and baboon256.raw from 8 bits to 1 bits.
![lena8](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/97d2de54-c240-4314-b88e-3605376406fe)
![lena7](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/6b5a75a9-9481-4027-a6fe-d0ecea881b34)
![lena6](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/9600b3dc-5321-4ad2-a38c-9f4126ef6caa)
![lena5](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/c8c70d3e-9069-41eb-b38f-f1e3b2740f8f)
![lena4](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/d2239d32-2405-4e65-8fe3-35bfd1643884)
![lena3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/d298621f-bdaf-4b32-b8ef-a5965f03ea05)
![lena2](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/2ea40c01-5b68-47a6-a187-7f2ac1384fa9)
![lena1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/9b046d93-7a23-46a1-b0ee-121c773a91d8)

![baboon8](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/b5e1e55a-2428-4456-bf43-1fb0c09389d5)
![baboon7](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/51f237ed-825e-48b3-813c-e4ab5cc14838)
![baboon6](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/97efdc0a-70b1-4727-aa6e-fc2d3069ccd1)
![baboon5](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/34e535b4-4c37-451f-8f41-570b53cbc147)
![baboon4](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/c7c60abe-8071-42ed-8925-c2a742ddfef8)
![baboon3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/6d3765be-2b31-43d7-913d-a6a6dcdc1bab)
![baboon2](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/1043ae08-ec5d-4fa8-9d57-e47d4ffa2ac1)
![baboon1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/64e9a4d8-83db-4015-8817-106e9f753649)
### 2.4
### Find out the solutions from start (0,14) to end (34,93) using D4, D8 and Dm distance on map100x100.
#### map100x100
![map100x100_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/380397a3-0c3d-46be-92b8-27cca8a873ec)
####  D4
![map_D4](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/3891c5d0-4ea2-4f41-8e00-c2168b17da41)
#### D8
![map_D8](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/b14b4316-db96-45ac-a96b-fbab74445da4)
#### Dm
![map_Dm](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/57fe7a14-fb7b-421a-9fc8-1aa6433d7f1a)






## ADIP_3 result:
### 3.1
### Use bit-plane slicing to separate cat_512.raw into eight layers, beginning from bit-plane 7 to bit-plane 0. 
![cat_512_7](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/84366bf3-3a68-4618-af25-4f443a26fff5)
![cat_512_6](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/49b82519-6be9-4cf8-9d50-c4bbb7b1744e)
![cat_512_5](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/3ba1e114-484d-4861-af4f-ea13f7ef91ed)
![cat_512_4](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/472d98a5-faae-410a-8417-e5e1800dd607)
![cat_512_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/601065f5-456a-47e4-bcb8-f03cf642004e)
![cat_512_2](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/8ca9e98b-e705-45dd-a01a-5963a410321f)
![cat_512_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/903f4788-4e4d-446f-857c-00044ebb7203)
![cat_512_0](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/fcb8d3db-fe4c-43cf-8e99-97df7259e6d2)
### Replace bit-plane 0 with the output of your Homework 1 Problem 2b, and synthesize them back to 8-bit image.
#### the output of Homework 1 Problem 2b
![JackieChen_512_binary](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/5dfd7e1c-b7e5-433e-8ea0-681c26b13beb)
#### Replace bit-plane 0 with the output of Homework 1 Problem 2b
![cat_512_synthesize_with_JackieChen](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/add96a71-5015-4618-8cd3-97e905ce9177)
#### check LSB bit plane 
![LSB_bit_plane](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/e76366e4-b01d-4504-8dcc-823c1d918e8a)
### 3.2.1
### Power-Law transformation, use at least two different sets of parameters on each image.
#### original image
![meerkat_dark_800x600](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/46582643-8d9c-4cc2-94c1-568d77ff50b8)
#### Power-Law
![meerkat_dark_1_25](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/5dccef5d-5f1e-45e7-8b9f-ad60ef284d36)
![meerkat_dark_1_17](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/1207512f-82eb-4177-b342-360f17c78cd4)
#### original image
![meerkat_bright_800x600](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/32a0a097-b3e7-4f39-a037-374728e3a2c4)
#### Power-Law
![meerkat_bright_3_5](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/7f397846-332d-484b-a574-43cade32d3ca)
![meerkat_bright_2_5](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/98538dad-4634-48df-b111-0dc10268dd9d)
#### original image
![meerkat_high_contrast_800x600](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/f781fb98-444e-4592-89ab-8eccc46608ed)
#### Power-Law
![meerkat_high_contrast_1_04](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/a284e063-7092-4078-95ea-bb9e4c521dd8)
![meerkat_high_contrast_0_97](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/775ffebf-24fa-4148-bda6-31dc41f6a165)

### 3.2.2
### Piecewise-Linear transformation
#### original image
![meerkat_dark_800x600](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/46582643-8d9c-4cc2-94c1-568d77ff50b8)
#### Piecewise-Linear
![meerkat_dark_piecewise_linear](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/1d0b18f6-7c0a-4603-a4dd-49dfb83e85a1)
#### original image
![meerkat_bright_800x600](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/32a0a097-b3e7-4f39-a037-374728e3a2c4)
#### Piecewise-Linear
![meerkat_bright_piecewise_linear](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/0f77b662-a32b-4f86-965d-008e0bf90791)
#### original image
![meerkat_high_contrast_800x600](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/f781fb98-444e-4592-89ab-8eccc46608ed)
#### Piecewise-Linear
![meerkat_high_contrast_piecewise_linear](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/9da57bfd-0f6e-44db-a038-fb59f89c3368)

### 3.3.1
### Plot the histograms of the three meerkat images
#### image
![meerkat_dark_800x600](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/46582643-8d9c-4cc2-94c1-568d77ff50b8)
#### histograms
![histogram_of meerkat_dark_equal](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/9b600c48-3c44-46dd-8fdc-7f96d810e369)
#### image
![meerkat_bright_800x600](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/32a0a097-b3e7-4f39-a037-374728e3a2c4)
#### histograms
![histogram_of meerkat_bright_equal](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/7639e21e-810a-4986-bfab-c5e7fce7a6fc)
#### image
![meerkat_high_contrast_800x600](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/f781fb98-444e-4592-89ab-8eccc46608ed)
#### histograms
![histogram_of meerkat_high_contrast_equal](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/eb2e2835-bdff-461f-815a-2c60d757c668)

### 3.3.2
### Apply histogram equalization on the three images in 3.3.1 and plot their equalized histograms and compare the histograms before and after histogram equalization.
#### dark image
![meerkat_dark_800x600](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/46582643-8d9c-4cc2-94c1-568d77ff50b8)
#### histogram equalization
![meerkat_dark_hist_equal](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/a92f28bd-9463-4278-a60b-b93e659c13c6)
#### bright image
![meerkat_bright_800x600](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/32a0a097-b3e7-4f39-a037-374728e3a2c4)
#### histogram equalization
![meerkat_bright_hist_equal](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/b8145b8e-7a2d-4a54-bfe3-487e22b6562a)
#### high contrast image
![meerkat_high_contrast_800x600](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/f781fb98-444e-4592-89ab-8eccc46608ed)
#### histogram equalization
![meerkat_high_contrast_hist_equal](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/17ce7c6e-4ac6-4dc7-b2ae-fac15a672c92)
####  histogram of dark image (after histogram equalization)
![histogram_of_meerkat_dark](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/d9443193-a956-4f77-9aaa-75b044d3576b)
####  histogram of bright image (after histogram equalization)
![histogram_of_meerkat_bright](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/d293520e-bc4f-47ca-852f-9f192ddc8e74)
####  histogram of high contrast image (after histogram equalization)
![histogram_of_meerkat_high_contrast](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/56c3f0e8-3c0e-4cdd-aef8-9ca3c02b2b9f)

### 3.3.3
### Show the histogram matched images of cat_512.raw using catch_300x168.raw and traffic_970x646.raw as histogram specifications respectively, compare and analyze the histograms of cat_512.raw before and after matching
#### cat_512
![cat_512_out](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/d0fac0a6-96da-4aab-90bd-cfb63a5b0be6)
#### catch
![catch_300x168_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/e9b96fe6-6056-4c3c-9107-d5644d8c6d7a)
#### traffic
![traffic_970x646_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/0963036a-f574-45a2-aee4-29ad7103cc82)
####  histogram matched image (using catch_300x168)
![cat_512_match_catch_cat](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/7b35ccc4-fe4c-4b65-a537-5510f919b24a)
####  histogram matched image (using traffic_970x646)
![cat_512_match_traffic](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/2a533d12-0436-40aa-9b36-0552a2e760ec)
####  histogram of cat_512
![histogram_of_cat_512](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/99e185f5-03a5-4059-bbbd-79d8bff2ab69)
####  histogram of catch
![histogram_of_catch_300x168](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/0e36c746-3f1a-4348-870d-8b4e6821c082)
####  histogram of traffic
![histogram_of_traffic_970x646](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/18705ba5-9d5c-4411-8497-ad5199cb3c1f)
####  histogram of histogram matched image (using catch_300x168)
![histogram_of_cat_512_match_catch_cat](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/f25ab360-7274-4956-873a-ba1a951863b6)
####  histogram of histogram matched image (using traffic_970x646)
![histogram_of_cat_512_match_traffic](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/ffa31820-56e4-41a1-ba3d-27eea115cdec)




## ADIP_4 result:
### 4.1.1
### show and discuss the results of two different Laplacian filters. To generate the results, implement and compare the differences in the four border processing approaches taught in class.
#### original image and noise image
![roof_640x427_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/2ada7f89-e9bc-4207-ab52-f241cf4d1094)
![roof_640x427_noise_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/cc8ea585-7c23-47c6-a12f-420eac4e3394)

#### Laplacian filter (4-neighborhoods)
##### smaller output
![roof_640x427_Lapalacian4_smaller_output](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/36f4bce9-19c9-4fe5-adef-9a17cdfd6e76)
![roof_640x427_noise_Lapalacian4_smaller_output](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/eb8c0779-2c1c-4958-982f-d5054b2dc7ae)
##### ad hoc
![roof_640x427_Lapalacian4_ad_hoc](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/efc8ce71-4880-48fc-a692-5b5bf1b34f4f)
![roof_640x427_noise_Lapalacian4_ad_hoc](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/67ca4254-d29b-4ff9-80d1-02f6f04d1c03)
##### zero padding
![roof_640x427_Lapalacian4_zero_padding](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/66236449-1eda-4a7c-9085-0ddf2bed8c8c)
![roof_640x427_noise_Lapalacian4_zero_padding](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/63fa60ca-70cb-4ca2-a6a7-c6812481401a)
##### replicaiton
![roof_640x427_Lapalacian4_replication](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/df956df3-cc43-4248-b6be-7ddf67ebdd45)
![roof_640x427_noise_Lapalacian4_replication](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/803b43ce-056e-4dba-a76e-bbcada48bf62)

#### Laplacian filter (8-neighborhoods)
##### smaller output
![roof_640x427_Lapalacia8_smaller_output](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/3fbd0682-cded-4aad-ab10-9b6af82f8b48)
![roof_640x427_noise_Lapalacian8_smaller_output](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/9e3c91c2-c94c-4506-a284-63c4e12dfcbd)
##### ad hoc
![roof_640x427_Lapalacian8_ad_hoc](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/9aa5d145-788e-4827-bb67-283a10b69cf3)
![roof_640x427_noise_Lapalacian8_ad_hoc](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/8f84b8b1-20c6-4855-b1e8-fcffa79d4ea1)
##### zero padding
![roof_640x427_Lapalacian8_zero_padding](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/916b3c79-588f-4deb-9b70-5d8892b17b74)
![roof_640x427_noise_Lapalacian8_zero_padding](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/119d0447-78fd-413c-91a8-327a50b8e253)
##### replicaiton
![roof_640x427_Lapalacian8_replication](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/87914e9e-a691-4303-a52f-3e9783fd7614)
![roof_640x427_noise_Lapalacian8_replication](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/6ed0ba12-dee2-4bd0-a80b-829023aa536b)


### 4.1.2
### Display and analyze the results of the individual directional Sobel filters as well as the combined one.
#### original image 
![roof_640x427_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/1d301d8c-0e18-462b-b80c-033fca0542cd)
#### Sobel Gy
![roof_640x427_Sobel_Gy_replication](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/f157c744-daec-4150-9dd7-0c4998624ff0)
#### Sobel Gx
![roof_640x427_Sobel_Gx_replication](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/315685f0-47b1-4cca-8daa-a50c9f8aabe1)
#### Sobel combine
![roof_640x427_Sobel_combine_replication](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/9b28ef28-e3b8-4574-9d85-39465ee27491)

#### noise image 
![roof_640x427_noise_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/5dc8f122-ee1d-48cc-b7d9-f7e6278550e4)
#### Sobel Gy
![roof_640x427_noise_Sobel_Gy_replication](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/f13f18c0-64fb-458f-ad76-44411d820ed0)
#### Sobel Gx
![roof_640x427_noise_Sobel_Gx_replication](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/88998d95-14d2-447e-b04a-6de9738c9a3e)
#### Sobel combine
![roof_640x427_noise_Sobel_combine_replication](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/9d98c3b8-5ac6-4a2e-94ca-4470a1d1e29d)



### 4.2.1
### Use a 5x5 mean filter to filter these two images and determine whether or not the histograms of the filtered images remain the same.
#### original image 
![block white_256_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/18e401e2-ed0f-44b1-ae21-af7757c5cff9)
#### mean filter
![block_white_256_mean](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/4e2fa7c6-62e2-417e-8982-abb5f35263e2)
#### histograms of the filtered image
![histogram of block_white_256_mean](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/db296983-8a06-427c-9bf7-2069107d265e)
#### original image 
![chessboard_256_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/919fdf89-681b-4ab3-816b-a3ce1048b97f)
#### mean filter
![chessboard_256_mean](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/6b1449d0-aff4-4ad3-adfa-12a2b2d0671a)
#### histograms of the filtered image
![histogram of chessboard_256_mean](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/59099619-a92a-4e41-8dfc-8594fe39341e)

### 4.2.2
#### On the baboon_256.raw, apply 3x3 and 5x5 Gaussian filters with sigma = 0.8, 1.3, 2.0.
#### original image 
![baboon_256_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/da175afb-fd83-49b6-b127-a28dd33c18cf)
#### 3x3 Gaussian filter with sigma = 0.8, 1.3, 2.0
![baboon_256_0_8_filter_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/7d72f390-452a-445b-9b6c-d8fd99dbba41)
![baboon_256_1_3_filter_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/ab0520d0-d1c6-4499-9222-37a2ccfaed21)
![baboon_256_2_0_filter_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/4e380382-2459-4512-8fb5-21e1fe06090b)
#### 5x5 Gaussian filter with sigma = 0.8, 1.3, 2.0
![baboon_256_0_8_filter_5](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/57795b7f-3a3e-474f-a051-c2ecb1cfcac5)
![baboon_256_1_3_filter_5](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/1023e81d-2fc9-434d-ad1d-cc3337ab9ab4)
![baboon_256_2_0_filter_5](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/4187b689-7817-43eb-b2eb-44fb0c30590c)


### 4.2.3
### Use the methods to improve and sharpen the image.
#### original image 
![house_blur_noise_790x720_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/476daa57-f3e3-499c-af11-35ed1dddd964)
#### mean filter
![house_blur_noise_790x720_median](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/74f200ec-dea8-4413-b476-6b349069bb1f)
#### Sobel Gy
![house_blur_noise_790x720_sobel_Gy](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/25f8a86a-6c55-4268-b50e-1d9ed245ecaf)
#### Sobel Gx
![house_blur_noise_790x720_sobel_Gx](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/4d1f1f0c-b5d9-491d-8bba-906a45b54df8)
#### mean filter + Sobel
![house_blur_noise_790x720_median_sobel](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/683d0908-eed7-47c5-8154-ecd6ea4b1f83)
#### mean filter + Sobel + histogram matching(with the image after performing mean filtering)
![house_blur_noise_790x720_median_sobel_match](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/2b9a8910-0229-4561-971c-c42fe2f43325)

### 4.3
### Apply Local Histogram Equalization on tsukuba_683x512.raw, and process it with at least three different mask sizes.
#### original image 
![tsukuba_683x512_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/63bc0cfe-d491-4e31-804e-9ec089a6f85d)
#### Apply Local Histogram Equalization (mask size: 3x3)
![tsukuba_683x512_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/8af3db6d-0134-442e-91d5-20559e0fea41)
#### Apply Local Histogram Equalization (mask size: 5x5)
![tsukuba_683x512_5](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/ed44a167-5e9d-4c72-bfd1-d1bdd7958423)
#### Apply Local Histogram Equalization (mask size: 7x7)
![tsukuba_683x512_7](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/6b26e203-4a7c-4c85-9d9d-735254219994)
#### Histogram of image (mask size: 3x3)
![histogram of tsukuba_683x512_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/05c65f29-19a2-4697-9309-16c51a06dc08)
#### Histogram of image (mask size: 5x5)
![histogram of tsukuba_683x512_5](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/250cf0a2-acce-4a2a-a839-d22deb97c2b3)
#### Histogram of image (mask size: 7x7)
![histogram of tsukuba_683x512_7](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/850a8949-192c-4474-8f89-786f26ebdaa1)







## ADIP_5 result:

### 5.1.1
### Write my own DFT subroutine and test it on images, Show the magnitude spectrum output. 
#### original image 
![rhombus_256_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/3e9801b7-aec3-4f4e-9dad-6aac92eb6a43)
#### my own DFT subroutine

#### original image 
![lena_256_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/bc965bb3-f3f5-4afe-ae39-f018be97a469)
#### my own DFT subroutine
![lena_256_mydft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/a3dcf65a-b958-498f-9524-e778a730d03e)
#### original image 
![sine_128_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/6c06e1c5-77bb-4a28-bbaa-09c37d826416)
#### my own DFT subroutine
![sine_128_mydft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/e7bd6830-563a-4863-8926-c3e4d3d2874a)

### 5.1.2
### Compare the output of Problem(1) with the output of the built-in DFT function on OpenCV. 

#### my own DFT subroutine
![rhombus_256_mydft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/96bf7c4e-955f-4e15-ba61-1b8ffcb19801)
![lena_256_mydft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/a3dcf65a-b958-498f-9524-e778a730d03e)
![sine_128_mydft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/e7bd6830-563a-4863-8926-c3e4d3d2874a)
#### Built-in DFT function on OpenCV
![rhombus_256_mat_dft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/17fbab86-3e05-461c-a48a-aec4ced43fb0)
![lena_256_mat_dft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/8c21fc72-2e26-4360-8d4b-e6959ada3f0b)
![sine_128_mat_dft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/0e84a911-580a-4075-b33a-63291fd485fa)

### 5.1.3
### Write my own IDFT subroutine and test it on DFT output in Problem 1.(1), show the images and compute the MSE between original images without transformation and the images that has been transformed by DFT+IDFT.

#### original image 
![rhombus_256_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/3e9801b7-aec3-4f4e-9dad-6aac92eb6a43)
#### my own IDFT subroutine
![rhombus_256_myidft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/09174b34-87d2-45e1-b560-afa38352ba5c)
#### original image 
![lena_256_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/bc965bb3-f3f5-4afe-ae39-f018be97a469)
#### my own IDFT subroutine
![lena_256_myidft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/a2f1e211-3ce8-4e39-b0b9-97a5cbeab2e7)
#### original image 
![sine_128_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/6c06e1c5-77bb-4a28-bbaa-09c37d826416)
#### my own IDFT subroutine
![sine_128_myidft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/5fa78c9a-bd94-4137-8006-0fd8a312f7bb)


### 5.1.4
### Compare the output of Problem(3) with the output of the built-in IDFT function on OpenCV. 

#### my own IDFT subroutine
![rhombus_256_myidft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/09174b34-87d2-45e1-b560-afa38352ba5c)
![lena_256_myidft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/a2f1e211-3ce8-4e39-b0b9-97a5cbeab2e7)
![sine_128_myidft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/5fa78c9a-bd94-4137-8006-0fd8a312f7bb)
#### Built-in IDFT function on OpenCV
![rhombus_256_mat_idft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/9a8dd645-f523-4b4d-8cc5-41a339629117)
![lena_256_mat_idft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/81691b06-3adb-427a-8f0b-f7b78a3d412c)
![sine_128_mat_idft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/a6465463-a46f-4b4f-81c8-54724bff001e)

### 5.1.5
### Study DCT and implement it, and test it on images in (1). Display spectrum results and compare them to the DFT output.
#### my own DFT subroutine
![rhombus_256_mydft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/96bf7c4e-955f-4e15-ba61-1b8ffcb19801)
![lena_256_mydft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/a3dcf65a-b958-498f-9524-e778a730d03e)
![sine_128_mydft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/e7bd6830-563a-4863-8926-c3e4d3d2874a)
#### my own DCT subroutine
![rhombus_256_mydct](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/83b140f3-12f0-416a-ba65-d46e25c317a4)
![lena_256_mydct](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/c8adfa6d-8b2e-4767-b999-b833572f8aba)
![sine_128_mydct](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/da59d103-387a-4b0e-a3e5-47716f08a8a2)

### 5.2.1
### Use Butterworth LPF and Butterworth HPF with D0 = 5,20,50 and n= 1,2,3 respectively, and show the magnitude spectrum and output image produced by IDFT.

#### Butterworth LPF with D0 = 5,20,50 and n= 1,2,3 respectively.
##### D0 = 5, n = 1
![raccoon_512_LPF_5_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/d153df47-b986-4e1d-b539-df940faab60d)
![raccoon_512_LPF_mag_5_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/370bddb3-1316-4abe-baf3-35225c5cd0ce)
##### D0 = 5, n = 2
![raccoon_512_LPF_5_2](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/c07bc040-6aae-4088-81fb-e832cf26144e)
![raccoon_512_LPF_mag_5_2](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/720c73cf-302d-4acb-a1e4-d8980e259f49)
##### D0 = 5, n = 3
![raccoon_512_LPF_5_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/13673a8b-a049-446f-a0bb-5f74d48b5674)
![raccoon_512_LPF_mag_5_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/5512692d-3c4f-4ca1-9d74-789f32eadd19)
##### D0 = 20, n = 1
![raccoon_512_LPF_20_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/be169ff9-ce05-4c56-ab9c-40b525436950)
![raccoon_512_LPF_mag_20_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/62453037-029e-4a81-a407-2ac264d4021d)
##### D0 = 20, n = 2
![raccoon_512_LPF_20_2](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/ab707763-0cc0-4c37-a419-382e7700fa93)
![raccoon_512_LPF_mag_20_2](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/cb8fc2cd-1f83-44a1-a704-599b05992e30)
##### D0 = 20, n = 3
![raccoon_512_LPF_20_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/fd004e48-7191-4225-8452-d549269a943d)
![raccoon_512_LPF_mag_20_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/994a072d-73b2-4a7a-8e1f-a2d93f2bbff1)
##### D0 = 50, n = 1
![raccoon_512_LPF_50_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/95dbf9a7-516d-4a71-959c-1efa1d3b9e14)
![raccoon_512_LPF_mag_50_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/c1ac760a-3767-479e-b204-69e84f297aae)
##### D0 = 50, n = 2
![raccoon_512_LPF_50_2](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/92bce4d8-87fe-4ba3-b9f7-7b8559326a89)
![raccoon_512_LPF_mag_50_2](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/4d1a5164-25fe-4869-b1f2-0d229384ecf3)
##### D0 = 50, n = 3
![raccoon_512_LPF_50_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/02a360e1-da9c-4115-8c05-4d2ef9b442cf)
![raccoon_512_LPF_mag_50_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/214a32c8-7cf5-492a-9fa3-9c5464c260eb)
#### Butterworth HPF with D0 = 5,20,50 and n= 1,2,3 respectively.
##### D0 = 5, n = 1
![raccoon_512_HPF_5_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/cfa8a6d5-4cb2-4246-a5f3-c8adf706bebd)
![raccoon_512_HPF_mag_5_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/65a5f93f-5738-41ea-a044-b81e3b57a580)
##### D0 = 5, n = 2
![raccoon_512_HPF_5_2](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/38122c51-348f-4d0b-9cf5-4333cfdc2ccb)
![raccoon_512_HPF_mag_5_2](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/00599483-5184-4683-ac7f-f8caeb55115b)
##### D0 = 5, n = 3
![raccoon_512_HPF_5_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/86e044a4-9930-4471-9b28-9095fec74457)
![raccoon_512_HPF_mag_5_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/b5cd8134-530b-4c31-8fe0-94090b3df362)
##### D0 = 20, n = 1
![raccoon_512_HPF_20_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/f8557047-2367-4a23-9d99-a324467d5a7b)
![raccoon_512_HPF_mag_20_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/122c8c72-a16a-4da9-863f-8fb46a64d928)
##### D0 = 20, n = 2
![raccoon_512_HPF_20_2](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/3a8ae719-2975-431a-a0d8-220878b5713b)
![raccoon_512_HPF_mag_20_2](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/465f10de-7ba9-48d1-8004-bbca86e24361)
##### D0 = 20, n = 3
![raccoon_512_HPF_20_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/b7b5ae4d-1953-49ed-865a-5021a86103a2)
![raccoon_512_HPF_mag_20_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/3e4f03de-1173-492c-a193-73962ac8a979)
##### D0 = 50, n = 1
![raccoon_512_HPF_50_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/2e16f5de-f056-4e36-af74-4f21840ec336)
![raccoon_512_HPF_mag_50_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/bf5b2d13-9509-458d-8fce-e6617f8bb13b)
##### D0 = 50, n = 2
![raccoon_512_HPF_50_2](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/5b7680de-e967-4295-a041-0d3a33255d51)
![raccoon_512_HPF_mag_50_2](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/dd98b38d-0326-45a5-bd00-bde7e284d92f)
##### D0 = 50, n = 3
![raccoon_512_HPF_50_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/35194395-2849-43c1-a544-a974b0098e50)
![raccoon_512_HPF_mag_50_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/4132fcbe-2ac5-4f52-b6c8-88180b053d06)






### 5.2.2
### Apply High-Frequency Emphasis Filtering to improve the high-frequency component of owl_blur_512.raw.
#### original image 
![owl_blur_512_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/0370ba92-e1c4-49c8-8d58-01abc3539285)
#### Apply High-Frequency Emphasis Filtering
![owl_blur_512_HFEmphasis](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/38f1b385-7d14-4935-8d8c-e1131cc9a55e)

### 5.3.1
### Use method i to add watermark to raccoon_512.raw, show the resulted magnitude spectrum and output image that resulted.
#### method i
![image](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/92921ca4-b0e2-4160-b43b-6e7d1b859a50)
#### watermark image
![mark_512_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/d16dd5c1-7364-4535-a7ec-6101792fed99)
#### raccoon_512
![raccoon_512_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/7b18391c-bea6-4c35-8f5a-ccf1f79f142a)
#### use method i to add watermark to reccoon_512 
![methodI_image](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/d35877b9-dffa-431c-b61c-97d06395442a)
#### magnitude spectrum
![methodI spectrum magnitude](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/1562003b-0c49-4dce-bcbc-6c648b99824f)

### 5.3.2
### Use method ii to add watermark to raccoon_512.raw, show the resulted magnitude spectrum and output image that resulted.
#### method ii
![image](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/58cbf779-ae3d-43e9-b9b5-bee024b4dc66)
#### watermark image
![mark_512_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/d16dd5c1-7364-4535-a7ec-6101792fed99)
#### raccoon_512
![raccoon_512_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/7b18391c-bea6-4c35-8f5a-ccf1f79f142a)
#### use method ii to add watermark to reccoon_512 
![methodII_image](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/96db7a44-6e55-4198-829e-e0fbc58ba631)
#### magnitude spectrum
![methodII spectrum magnitude](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/49865cce-1e35-493e-82cf-44663d0d6222)
### 5.4
### Apply a homomorphic filter to house_512.raw and experiment to find the best set
#### homomorphic filter
![house_HomomorphicFilter](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/b9d3712e-cd10-4e54-a797-73ee99dd86b9)
#### histogram equalizaion
![house_512_LocalHistogramEqu](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/150abe8a-aedd-482b-96de-df36da4a9079)
#### local histogram equalizaion
![house_512_HistogramEqu](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/2c2bc559-66b5-4b4d-b53f-fc7fead27d6c)








## ADIP_6 result:

### 6.1
### Use Morphology to remove noise and then repair letters that have been unintentionally damaged by denoising.
#### original image 
![words_512_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/9d73e5d0-52e4-4617-82f3-798785b313c3)
#### use Morphology to remove noise 
![words_512_morph](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/a793cdb9-ff80-4a14-9be6-1f51e35ebf33)


### 6.2.1
### Use SE_5x5 as structure element to perform four morphological operations separately on grayscale image check_613x237.raw.
#### original image 
![check_613x237_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/25bc92c3-0acb-488a-8ef4-be6b87589a22)
#### erosion
![check_613x237_erode](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/7a4f0ad1-494b-4d1a-9e78-bf9d6557b12f)
#### dilation
![check_613x237_dilate](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/d6e142ce-a919-4500-86d7-1065d24b8dd5)
#### opening
![check_613x237_opening](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/d805d68b-dcf0-4a94-918a-3a88f4f8f0f2)
#### closing
![check_613x237_closing](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/c33c4797-e404-4200-8a24-f60d58b0fde9)

### 6.2.2
### As in (1), but first rotate structure SE_5x5 by 90。，and use it in erosion and dilation separately.
#### original image 
![check_613x237_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/25bc92c3-0acb-488a-8ef4-be6b87589a22)
#### erosion
![check_613x237_erode_rotate](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/4db2357d-f6c9-4fdc-aefa-7c9e5561ffe9)
#### dilation
![check_613x237_dilate_rotate](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/b561ff35-55b5-4c95-b302-1e09a70d308c)

### 6.3
### Use morphology to generate a trimap image for an output like Trimap_example
#### original image 
![monster_600_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/cf5c9d2b-f5e2-4ecd-9776-d6d9d0fab748)
#### trimap
![monster_600_trimap](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/ccd43500-a920-49e6-8953-62ee23db3aad)

### 6.4
### Use morphology to repair damaged roads, and then extract and thin the roads to calculate steps of the shortest path from start point to end point.
#### original image 
![map_512_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/8c5e69df-d047-48fd-bbdb-3281f8fe85cb)
#### Use morphology to repair damaged roads
![map_512_repair](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/835e8070-9cef-4a67-b3ad-928fbec65ad5)
#### calculate steps
![map_512_path](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/62515910-5c17-4e35-a15f-4c7c83224ce0)
































