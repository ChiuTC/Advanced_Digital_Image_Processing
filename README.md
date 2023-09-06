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
#### Show the histogram matched images of cat_512.raw using catch_300x168.raw and traffic_970x646.raw as histogram specifications respectively, compare and analyze the histograms of cat_512.raw before and after matching
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











