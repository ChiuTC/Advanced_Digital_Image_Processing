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
![cat_512_7](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/d5283bd5-bdb9-42f3-a7d4-b82d258fe26e)
![cat_512_6](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/670aca96-a6e9-47ba-ac59-0589b19c6ef0)
![cat_512_5](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/60b7e5ff-75cc-48dc-a1b3-bb24141de9b0)
![cat_512_4](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/591a19fd-c250-4f7f-aa38-740516d0d106)
![cat_512_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/0bc2e820-865a-4f93-bedb-70c8571dbfd7)
![cat_512_2](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/b9461bff-f4af-4866-8bf0-992d7105438a)
![cat_512_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/fa0e0a11-3374-422c-a70c-5b47d199c6dd)
![cat_512_0](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/ab686cf9-032f-4f07-bcba-f6345470210e)  
### Replace bit-plane 0 with the output of your Homework 1 Problem 2b, and synthesize them back to 8-bit image.
#### the output of Homework 1 Problem 2b
![JackieChen_512_binary](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/737c6b12-c3ac-4d87-995f-72b44315220f)
#### Replace bit-plane 0 with the output of Homework 1 Problem 2b
![cat_512_synthesize_with_JackieChen](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/4c501daf-4463-400b-a022-bc8a027dfdb6)
#### check LSB bit plane 
![LSB_bit_plane](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/6b8dc7ba-5312-472b-8b06-b797a57b2009)
### 3.2.1
### Power-Law transformation, use at least two different sets of parameters on each image.
#### original image
![meerkat_dark_800x600](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/3853edbe-edf9-42a8-bfa0-bbd6a5401a22)
#### Power-Law
![meerkat_dark_1_25](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/ca659e71-eb92-44ad-9b99-5d2fd288d972)
![meerkat_dark_1_17](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/1cc1f88f-0d3f-4e48-85cd-888b26e44cdd)
#### original image
![meerkat_bright_800x600](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/6defdbe6-5a54-427c-ac8e-13a82caa0cf3)
#### Power-Law
![meerkat_bright_3_5](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/be498401-fa8d-468e-b0f2-af3d85e7637f)
![meerkat_bright_2_5](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/312efcee-1ef6-48b5-a49d-5541daed77f5)
#### original image
![meerkat_high_contrast_800x600](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/b623d337-6b6e-4773-9f63-1db2dc61436d)
#### Power-Law
![meerkat_high_contrast_1_04](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/77c9f03b-a75e-4bc4-918e-f515b78e5198)
![meerkat_high_contrast_0_97](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/6a529938-931a-439a-9a28-53cf0943afc0)

### 3.2.2
### Piecewise-Linear transformation
#### original image
![meerkat_dark_800x600](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/3853edbe-edf9-42a8-bfa0-bbd6a5401a22)
#### Piecewise-Linear
![meerkat_dark_piecewise_linear](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/62fd8357-0482-4594-a094-3a9686467285)
#### original image
![meerkat_bright_800x600](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/6defdbe6-5a54-427c-ac8e-13a82caa0cf3)
#### Piecewise-Linear
![meerkat_bright_piecewise_linear](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/c08a1c7b-6d3f-4f68-9689-42231de159fb)
#### original image
![meerkat_high_contrast_800x600_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/56c3f465-8ba9-4b1c-9fb3-3246708e1135)
#### Piecewise-Linear
![meerkat_high_contrast_piecewise_linear](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/b76afefe-8b66-4d08-a016-9c4d4568f0d5)

### 3.3.1
### Plot the histograms of the three meerkat images
#### image
![meerkat_dark_800x600](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/3853edbe-edf9-42a8-bfa0-bbd6a5401a22)
#### histograms
![histogram_of meerkat_dark_equal](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/dec46b14-ee06-4e9d-a28f-2795e3519eba)
#### image
![meerkat_bright_800x600](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/6defdbe6-5a54-427c-ac8e-13a82caa0cf3)
#### histograms
![histogram_of meerkat_bright_equal](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/eae0ec6a-781b-4ae2-8899-6f67ffee4a4b)
#### image
![meerkat_high_contrast_800x600_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/56c3f465-8ba9-4b1c-9fb3-3246708e1135)
#### histograms
![histogram_of meerkat_high_contrast_equal](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/a3277958-6c82-4cb0-a1b7-8134b0533641)

### 3.3.2
### Apply histogram equalization on the three images in 3.3.1 and plot their equalized histograms and compare the histograms before and after histogram equalization.
#### dark image
![meerkat_dark_800x600](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/3853edbe-edf9-42a8-bfa0-bbd6a5401a22)
#### histogram equalization
![meerkat_dark_hist_equal](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/d75697f2-3404-4117-90b9-253d2ebac31c)
#### bright image
![meerkat_bright_800x600](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/6defdbe6-5a54-427c-ac8e-13a82caa0cf3)
#### histogram equalization
![meerkat_bright_hist_equal](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/15e073ed-7135-4fa5-a6ee-0885eba95564)
#### high contrast image
![meerkat_high_contrast_800x600_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/56c3f465-8ba9-4b1c-9fb3-3246708e1135)
#### histogram equalization
![meerkat_high_contrast_hist_equal](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/56cc62ce-7149-4ac6-b469-6354f701af68)
####  histogram of dark image (after histogram equalization)
![histogram_of_meerkat_dark](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/fbd23af3-ac7b-4a3e-9b42-3495592a3b0a)
####  histogram of bright image (after histogram equalization)
![histogram_of_meerkat_bright](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/d3365b3e-3281-43d4-8be9-85219a485f27)
####  histogram of high contrast image (after histogram equalization)
![histogram_of_meerkat_high_contrast](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/b377b58d-cd1c-4404-af01-3b95630a6d5b)

### 3.3.3
### Show the histogram matched images of cat_512.raw using catch_300x168.raw and traffic_970x646.raw as histogram specifications respectively, compare and analyze the histograms of cat_512.raw before and after matching
#### cat_512
![cat_512_out](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/5d8cd685-9dbb-4cf5-b581-342fe8cee293)
#### catch
![catch_300x168_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/6f93a654-3bb1-432b-8ed8-9e31d3c56721)
#### traffic
![traffic_970x646_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/d2a78f2b-b0a6-4030-96e1-7eccca90f92a)
####  histogram matched image (using catch_300x168)
![cat_512_match_catch_cat](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/28f44587-6629-441c-953e-92b1de627d22)
####  histogram matched image (using traffic_970x646)
![cat_512_match_traffic](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/b57c2c51-7568-4537-affc-4afff9f89d2f)
####  histogram of cat_512
![histogram_of_cat_512](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/5f2a73da-f051-4c47-96f1-9dbafe6e7aef)
####  histogram of catch
![histogram_of_catch_300x168](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/d8bc36b8-bf52-40d9-8e61-af9a8bc355be)
####  histogram of traffic
![histogram_of_traffic_970x646](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/ecaf81c6-5161-4ed8-97d0-32b15f25fb94)
####  histogram of histogram matched image (using catch_300x168)
![histogram_of_cat_512_match_catch_cat](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/94410181-cdfd-48fa-a346-44898928f564)
####  histogram of histogram matched image (using traffic_970x646)
![histogram_of_cat_512_match_traffic](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/93870a6b-7d8a-48fa-afa7-bc4b472b2347)

![meerkat_high_contrast_piecewise_linear](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/9da57bfd-0f6e-44db-a038-fb59f89c3368)
![meerkat_high_contrast_hist_equal](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/17ce7c6e-4ac6-4dc7-b2ae-fac15a672c92)
![meerkat_high_contrast_800x600](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/f781fb98-444e-4592-89ab-8eccc46608ed)
![meerkat_high_contrast_1_04](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/a284e063-7092-4078-95ea-bb9e4c521dd8)
![meerkat_high_contrast_0_97](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/775ffebf-24fa-4148-bda6-31dc41f6a165)
![meerkat_dark_piecewise_linear](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/1d0b18f6-7c0a-4603-a4dd-49dfb83e85a1)
![meerkat_dark_hist_equal](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/a92f28bd-9463-4278-a60b-b93e659c13c6)
![meerkat_dark_800x600](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/46582643-8d9c-4cc2-94c1-568d77ff50b8)
![meerkat_dark_1_25](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/5dccef5d-5f1e-45e7-8b9f-ad60ef284d36)
![meerkat_dark_1_17](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/1207512f-82eb-4177-b342-360f17c78cd4)
![meerkat_bright_piecewise_linear](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/0f77b662-a32b-4f86-965d-008e0bf90791)
![meerkat_bright_hist_equal](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/b8145b8e-7a2d-4a54-bfe3-487e22b6562a)
![meerkat_bright_800x600](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/32a0a097-b3e7-4f39-a037-374728e3a2c4)
![meerkat_bright_3_5](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/7f397846-332d-484b-a574-43cade32d3ca)
![meerkat_bright_2_5](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/98538dad-4634-48df-b111-0dc10268dd9d)
![LSB_bit_plane](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/e76366e4-b01d-4504-8dcc-823c1d918e8a)
![JackieChen_512_binary](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/5dfd7e1c-b7e5-433e-8ea0-681c26b13beb)
![histogram_of_traffic_970x646](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/18705ba5-9d5c-4411-8497-ad5199cb3c1f)
![histogram_of_meerkat_high_contrast](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/56c3f0e8-3c0e-4cdd-aef8-9ca3c02b2b9f)
![histogram_of_meerkat_dark](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/d9443193-a956-4f77-9aaa-75b044d3576b)
![histogram_of_meerkat_bright](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/d293520e-bc4f-47ca-852f-9f192ddc8e74)
![histogram_of_catch_300x168](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/0e36c746-3f1a-4348-870d-8b4e6821c082)
![histogram_of_cat_512_match_traffic](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/ffa31820-56e4-41a1-ba3d-27eea115cdec)
![histogram_of_cat_512_match_catch_cat](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/f25ab360-7274-4956-873a-ba1a951863b6)
![histogram_of_cat_512](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/99e185f5-03a5-4059-bbbd-79d8bff2ab69)
![histogram_of meerkat_high_contrast_equal](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/eb2e2835-bdff-461f-815a-2c60d757c668)
![histogram_of meerkat_dark_equal](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/9b600c48-3c44-46dd-8fdc-7f96d810e369)
![histogram_of meerkat_bright_equal](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/7639e21e-810a-4986-bfab-c5e7fce7a6fc)
![cat_512_synthesize_with_JackieChen](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/add96a71-5015-4618-8cd3-97e905ce9177)
![cat_512_synthesize](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/772dcfc8-2dc0-467d-a6ae-8f526bbe5ffe)
![cat_512_out](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/d0fac0a6-96da-4aab-90bd-cfb63a5b0be6)
![cat_512_match_traffic](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/2a533d12-0436-40aa-9b36-0552a2e760ec)
![cat_512_match_catch_cat](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/7b35ccc4-fe4c-4b65-a537-5510f919b24a)
![cat_512_equal](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/ce736805-1d61-433f-b2d3-1833e298e087)
![cat_512_7](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/84366bf3-3a68-4618-af25-4f443a26fff5)
![cat_512_6](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/49b82519-6be9-4cf8-9d50-c4bbb7b1744e)
![cat_512_5](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/3ba1e114-484d-4861-af4f-ea13f7ef91ed)
![cat_512_4](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/472d98a5-faae-410a-8417-e5e1800dd607)
![cat_512_3](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/601065f5-456a-47e4-bcb8-f03cf642004e)
![cat_512_2](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/8ca9e98b-e705-45dd-a01a-5963a410321f)
![cat_512_1](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/903f4788-4e4d-446f-857c-00044ebb7203)
![cat_512_0](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/fcb8d3db-fe4c-43cf-8e99-97df7259e6d2)
![traffic_970x646_equal](https://github.com/ChiuTC/Advanced_Digital_Image_Processing/assets/99594456/45047a5a-a970-41cd-916f-b9544a42470c)







## ADIP_4 result:
### 4.1.1
### show and discuss the results of two different Laplacian filters. To generate the results, implement and compare the differences in the four border processing approaches taught in class.
#### original image and noise image
![roof_640x427_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/bae17eee-3832-47d3-a376-480ef540ab08)
![roof_640x427_noise_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/60d66e1c-a3da-4f33-bc00-c746d851061c)

#### Laplacian filter (4-neighborhoods)
##### smaller output
![roof_640x427_Lapalacian4_smaller_output](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/c2b196c5-5a65-4b0f-8365-74d3d723f928)
![roof_640x427_noise_Lapalacian4_smaller_output](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/0c960e0d-76f0-470e-8dd3-0cc5b3ce5ea9)
##### ad hoc
![roof_640x427_Lapalacian4_ad_hoc](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/effd743d-b104-49da-ae95-64e63c0bfd1b)
![roof_640x427_noise_Lapalacian4_ad_hoc](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/a82d4cef-0a74-4a5f-8cfb-61a69d67ac39)
##### zero padding
![roof_640x427_Lapalacian4_zero_padding](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/440d2a60-d056-4a7b-b4be-e5bed87c891a)
![roof_640x427_noise_Lapalacian4_zero_padding](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/6363e6e4-7293-4990-a507-33e21fd2fa87)
##### replicaiton
![roof_640x427_Lapalacian4_replication](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/2805ce02-136b-4e72-a791-0a5af4840a8a)
![roof_640x427_noise_Lapalacian4_replication](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/575ce50f-11d6-42b5-9972-e1983121c0de)

#### Laplacian filter (8-neighborhoods)
##### smaller output
![roof_640x427_Lapalacia8_smaller_output](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/744f2736-3e65-406f-b14f-6309c7432111)
![roof_640x427_noise_Lapalacian8_smaller_output](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/66e5cd65-c720-4fcf-9ea6-1090566f528c)
##### ad hoc
![roof_640x427_Lapalacian8_ad_hoc](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/bb47b966-8b7f-45b7-a24a-3d3913d898f1)
![roof_640x427_noise_Lapalacian8_ad_hoc](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/fc80a8f3-c91f-4f63-9ec4-9901894af780)
##### zero padding
![roof_640x427_Lapalacian8_zero_padding](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/9df5d807-a75c-4bae-b947-54636d60f4fc)
![roof_640x427_noise_Lapalacian8_zero_padding](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/b55550a3-13d2-46a1-a2f1-5e5abbc5f0e6)
##### replicaiton
![roof_640x427_Lapalacian8_replication](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/469f44ce-babc-44e2-b578-0bb5a2e0fa85)
![roof_640x427_noise_Lapalacian8_replication](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/3ab3f96d-e92f-4eeb-9a58-ff0791bca7a0)


### 4.1.2
### Display and analyze the results of the individual directional Sobel filters as well as the combined one.
#### original image 
![roof_640x427_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/bae17eee-3832-47d3-a376-480ef540ab08)
#### Sobel Gy
![roof_640x427_Sobel_Gy_replication](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/081798c0-8b27-4554-b61b-ff36aa9f50c9)
#### Sobel Gx
![roof_640x427_Sobel_Gx_replication](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/829fbecf-5549-4e7e-8e4f-08c4573cc58b)
#### Sobel combine
![roof_640x427_Sobel_combine_replication](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/aa1ca307-aace-42c7-9ba8-89c86423ba37)

#### noise image 
![roof_640x427_noise_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/60d66e1c-a3da-4f33-bc00-c746d851061c)
#### Sobel Gy
![roof_640x427_noise_Sobel_Gy_replication](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/f187baf3-9d74-45df-a001-add8c84ae3a5)
#### Sobel Gx
![roof_640x427_noise_Sobel_Gx_replication](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/923bb6cb-5d79-4874-be55-f3a1a72a54a0)
#### Sobel combine
![roof_640x427_noise_Sobel_combine_replication](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/ac85a7d5-a926-4857-b3bf-f5828a62faed)




### 4.2.1
### Use a 5x5 mean filter to filter these two images and determine whether or not the histograms of the filtered images remain the same.
#### original image 
![block white_256_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/0235e73e-e4d5-481d-a2a4-16cbc92c61c4)
#### mean filter
![block_white_256_mean](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/9b932954-9fda-472e-8e00-8ee8ab88fd8e)
#### histograms of the filtered image
![histogram of block_white_256_mean](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/66c7110d-f2b0-480f-95a9-93750afc46de)
#### original image 
![chessboard_256_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/c397ab4a-c444-451d-af19-a9f8ad7988cb)
#### mean filter
![chessboard_256_mean](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/19ccb709-7c35-4dbc-a262-f23e31dbe82a)
#### histograms of the filtered image
![histogram of chessboard_256_mean](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/c9ea2f23-e715-4673-88a7-b742715acb79)

### 4.2.2
#### On the baboon_256.raw, apply 3x3 and 5x5 Gaussian filters with sigma = 0.8, 1.3, 2.0.
#### original image 
![baboon_256_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/4d4c32bf-6ab0-4e6b-b753-19bd7aaa0e51)
#### 3x3 Gaussian filter with sigma = 0.8, 1.3, 2.0
![baboon_256_0_8_filter_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/857a5b11-a92c-4ba5-a3c1-fdc901c7138e)
![baboon_256_1_3_filter_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/54dd3f1f-06ce-4a44-8673-8f9493020583)
![baboon_256_2_0_filter_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/f04b8fcd-55ee-4566-ac52-6d78fdae6d1b)
#### 5x5 Gaussian filter with sigma = 0.8, 1.3, 2.0
![baboon_256_0_8_filter_5](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/b11d6b1d-00ef-4f71-bf16-8eec8d4ffa2e)
![baboon_256_1_3_filter_5](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/f148e061-115c-48b0-9e0a-ee3b1f6075a1)
![baboon_256_2_0_filter_5](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/1d91c396-3c4a-4ab8-b3ac-29f6ec27acd5)

### 4.2.3
### Use the methods to improve and sharpen the image.
#### original image 
![house_blur_noise_790x720_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/6e36f2cf-3a49-4418-854f-e068e5c1549d)
#### mean filter
![house_blur_noise_790x720_median](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/0b6df291-1768-4f9e-9f39-5f28c7045dc1)
#### Sobel Gy
![house_blur_noise_790x720_sobel_Gy](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/1a71010e-5069-4160-b0a9-ea475ffeff31)
#### Sobel Gx
![house_blur_noise_790x720_sobel_Gx](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/370cddb4-b235-443d-9c6c-765961d0e715)
#### mean filter + Sobel
![house_blur_noise_790x720_median_sobel](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/38df1b50-5f68-4f57-b91c-3bdbe30d4539)
#### mean filter + Sobel + histogram matching(with the image after performing mean filtering)
![house_blur_noise_790x720_median_sobel_match](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/bdbd4e0a-a890-44d4-a54b-8b13afee3797)

### 4.3
### Apply Local Histogram Equalization on tsukuba_683x512.raw, and process it with at least three different mask sizes.
#### original image 
![tsukuba_683x512_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/1a3a7884-f55c-466f-83ed-45d115b984ae)
#### Apply Local Histogram Equalization (mask size: 3x3)
![tsukuba_683x512_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/a5afc17b-a92e-431e-96df-1947f0857c2e)
#### Apply Local Histogram Equalization (mask size: 5x5)
![tsukuba_683x512_5](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/98762374-6387-4481-b4ba-9e0b128fff4f)
#### Apply Local Histogram Equalization (mask size: 7x7)
![tsukuba_683x512_7](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/fafa7102-258b-4863-81b5-1c99d45635c6)
#### Histogram of image (mask size: 3x3)
![histogram of tsukuba_683x512_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/eb70dc75-4cb2-4363-a1ec-581ff5d23274)
#### Histogram of image (mask size: 5x5)
![histogram of tsukuba_683x512_5](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/16280864-6650-49c6-92f1-a5e9412cffca)
#### Histogram of image (mask size: 7x7)
![histogram of tsukuba_683x512_7](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/4315081e-a814-4b3e-aa5b-b0b56cf2753e)










## ADIP_5 result:

### 5.1.1
### Write my own DFT subroutine and test it on images, Show the magnitude spectrum output. 
#### original image 
![rhombus_256_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/3e9801b7-aec3-4f4e-9dad-6aac92eb6a43)
#### my own DFT subroutine
![rhombus_256_mydft](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/96bf7c4e-955f-4e15-ba61-1b8ffcb19801)
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
![raccoon_512_LPF_5_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/4eacdd2f-393d-4812-a542-bebf7db881b2)
![raccoon_512_LPF_mag_5_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/4b28beea-aa35-40db-b285-28adab8d6009)
##### D0 = 5, n = 2
![raccoon_512_LPF_5_2](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/d839b056-9946-466f-b6da-5a9e016a7566)
![raccoon_512_LPF_mag_5_2](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/9b85577e-64d0-4b6f-bd29-119536db896c)
##### D0 = 5, n = 3
![raccoon_512_LPF_5_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/17f91ad7-4764-4dce-9967-4c4d6c6d6e90)
![raccoon_512_LPF_mag_5_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/86518467-ccaf-415f-9dec-c3c1032fd3d0)
##### D0 = 20, n = 1
![raccoon_512_LPF_20_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/ef5b530d-5099-46e8-81f9-1b45c3cf1941)
![raccoon_512_LPF_mag_20_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/cf188b64-42a2-4b70-920c-4f618d89c7da)
##### D0 = 20, n = 2
![raccoon_512_LPF_20_2](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/a1c4cf6d-e44a-43cc-8491-4cd40a3e7250)
![raccoon_512_LPF_mag_20_2](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/ab7963e6-28a7-43d7-b34c-cb1d34c34f80)
##### D0 = 20, n = 3
![raccoon_512_LPF_20_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/4e763dcd-5f78-4f22-a2b4-97a2a4c39f2f)
![raccoon_512_LPF_mag_20_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/3949fe02-c7dc-4587-95ab-fc5a6075d5f2)
##### D0 = 50, n = 1
![raccoon_512_LPF_50_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/1b6afd00-e05d-43bf-af82-cbe565bcd8e5)
![raccoon_512_LPF_mag_50_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/d2868eaa-1f1d-4952-8df5-e6ab94ea7048)
##### D0 = 50, n = 2
![raccoon_512_LPF_50_2](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/39647d15-6052-41e6-a2b8-6a4db6f3b5df)
![raccoon_512_LPF_mag_50_2](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/ff61fa83-fe48-454e-ad35-185ddd7688bc)
##### D0 = 50, n = 3
![raccoon_512_LPF_50_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/7d1a420a-d204-45f9-823b-670281645666)
![raccoon_512_LPF_mag_50_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/c34062e2-51d5-41a2-9433-3ecd25287072)
#### Butterworth HPF with D0 = 5,20,50 and n= 1,2,3 respectively.
##### D0 = 5, n = 1
![raccoon_512_HPF_5_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/44e6d1cd-4268-48d9-8a69-ee3faabff148)
![raccoon_512_HPF_mag_5_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/6bd68020-9653-473d-b27d-f6c2069b3bda)
##### D0 = 5, n = 2
![raccoon_512_HPF_5_2](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/65b2ef09-ce29-4f4b-a9e3-e293fe8a1bf6)
![raccoon_512_HPF_mag_5_2](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/304e4477-228c-4aca-8378-252618b8e203)
##### D0 = 5, n = 3
![raccoon_512_HPF_5_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/fe9fef84-6c6a-4532-affd-82647ad6e566)
![raccoon_512_HPF_mag_5_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/931491eb-f65b-4959-8afe-2707d1e09498)
##### D0 = 20, n = 1
![raccoon_512_HPF_20_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/24ccef4e-198f-419b-b7eb-b1ebd544a5a6)
![raccoon_512_HPF_mag_20_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/2cc4154b-de8c-4d31-b6cf-3a51f0e955c0)
##### D0 = 20, n = 2
![raccoon_512_HPF_20_2](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/500ea1b9-4f1f-47f9-8226-5912f0dfa80a)
![raccoon_512_HPF_mag_20_2](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/7c274b94-b3cb-400a-ad4b-bb7d45ed22d7)
##### D0 = 20, n = 3
![raccoon_512_HPF_20_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/53b55f4e-d704-43a4-880b-00fffe68af86)
![raccoon_512_HPF_mag_20_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/43b8f0cd-eee0-4ad4-b680-b20d41ac2b07)
##### D0 = 50, n = 1
![raccoon_512_HPF_50_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/f2499496-8b83-4dd1-85db-164a233bf4e4)
![raccoon_512_HPF_mag_50_1](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/95517d1e-eac0-4c3a-8752-ff1fae1c45dc)
##### D0 = 50, n = 2
![raccoon_512_HPF_50_2](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/08cce10f-271d-48bb-919d-638666cf050a)
![raccoon_512_HPF_mag_50_2](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/30efce2f-395d-44f9-88f8-79393b32e2b4)
##### D0 = 50, n = 3
![raccoon_512_HPF_50_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/166399ef-44cc-4882-8542-f0b10ba81b78)
![raccoon_512_HPF_mag_50_3](https://github.com/aFatHand/Advanced_Digital_Image_Processing/assets/99594456/062416dc-4648-4463-8abb-cf128dc06e54)
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
































