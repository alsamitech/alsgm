#ifndef ALSAMI_VULKAN_MAIN_HEADER_OPENGL
#define ALSAMI_VULKAN_MAIN_HEADER_OPENGL

VkInstance vulk_init;

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
uint32_t glfwExtensionCount=0;
const char glfwExtensions;

int vern1;
int vern2;
int vern3;

void win_init(){
        // Tells GLFW to not create an OpenGL context
        glfwWindowHint(GLFW_CLIENT_API,GLFW_NO_API);
        glgwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);


}

void vulk_inst_create(){
  VkApplicationInfo vulk_appinfo{};
  vulk_appinfo.sType-VK_STRUCTURE_TYPE_APPLICATION_INFO;
  vulk_appinfo.pApplicationInfo= vulk_als_appnm;
  appInfo.applicationVersion=VK_MAKE_VERSION(vern1,vern2,vern3);
  appInfo.pEngineName="alsgm-vulk";
  appInfo.engineVersion=VK_MAKE_VERSION(1,2,9);
  appInfo.apiVersion=VK_API_VERSION_1_0;
  vkInstanceCreateInfo vulk_cinfo{};
  vulk_cinfo.sType=VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  vulk_cinfo.pApplicationInfo=&vulk_appinfo;

}

void vulk_init(){
  vulk_inst_create();

}

void vulk_wlp(){
  while(!glfwWindowShouldClose(window)){
    glfwPollEvents();
  }
}

void vulk_cleanup(){
  glfwDestroyWindow(window);
  glfwTerminate();
}

void vulk_run(){
        win_init();
        vulk_init();
        vulk_wlp();
        vulk_cleanup();
        
}       

#endif
