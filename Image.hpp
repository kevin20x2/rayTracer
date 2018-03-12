#ifndef TRACER_IMAGE_H
#define TRACER_IMAGE_H 

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

struct Image{
    Image(const std::string & file_name):
        file_name_(file_name)
    {
        data_ptr_ = stbi_load(file_name_.c_str(),&width_,&height_,&channel_,0);
        if(data_ptr == nullptr)
        {
            printf("load image error..");
        }
    }
    ~Image()
    {
        stbi_image_free(data_ptr_);
    }
    unsigned char * data_ptr_;
    std::string file_name_;
    int width_;
    int height_;
    int channel_;
};
#endif