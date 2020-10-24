#ifndef ALSAMI_VULKAN_MAIN_HEADER_OPENGL
#define ALSAMI_VULKAN_MAIN_HEADER_OPENGL


/*
 *      ALSGM CODENAME YIN
 *      VULKAN SUPPORT COMPONENT
 *
 *      OFFICIAL PUBLIC REPOSITORY
 *      https://github.com/alsamitech/alsgm
 *
 * */

#include <stdio.h>
#include <stdlib.h>

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

const uint32_t WIDTH=800;
const uint32_t HEIGHT=600;

void win_init(){
        // Tells GLFW to not create an OpenGL context
        glfwWindowHint(GLFW_CLIENT_API,GLFW_NO_API);
        glgwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);


}

void vulk_run(){
        win_init();
        vulk_init();
        vulk_wlp();
        vulk_cleanup();
        
}       

#endif
