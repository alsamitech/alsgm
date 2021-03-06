#ifndef ALSAMI_VULKAN_MAIN_HEADER_OPENGL
#define ALSAMI_VULKAN_MAIN_HEADER_OPENGL

#define ALS_RUNTIME_ERROR 50

//#include "tarray.h"

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

// Requires Vulkan SDK
// https://vulkan.lunarg.com/sdk/home#linux
#include <vulkan/vulkan.hpp>
#ifdef GLFW_VULK
#include <GLFW/glfw3.h>
#endif
#include "renderer.h"
#ifdef __cplusplus
extern "C" {
#endif
FILE *vulk_filelgr;

void vulkanlogger_alsami(unsigned int lgr_md, const char* lgr_msg){

    vulk_filelgr=fopen("vulk_runtime.als.log", "w+");

    fprintf(vulk_filelgr, "%s\n", lgr_msg);

}
#ifdef __cplusplus
}
#endif

/*
 *  The Vulkan module for ALSGM (Codename Yin) Overwrites the Runtime Logs every time it starts.
 *  This is just to save space. If something is truly critical, the module will just log it to console.
 *
 **/

/*verification stuff*/
#ifdef NDEBUG
  const bool enableValidationLayers=false;
#else
  const bool enableValidationLayers=true;
#endif

void gm_cmdpool_init(){
    VkCommandPool cmd_pool;
    VkCommandPoolCreateInfo gm_pool_info_x;
    gm_pool_info_x.sType            =VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    gm_pool_info_x.queueFamilyIndex = Renderer::vulk_graphics_family_index;
    gm_pool_info_x.flags            =VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    vkCreateCommandPool(Renderer::a_device,&gm_pool_info_x, nullptr, &cmd_pool);

}

#ifdef GLFW_VULK
bool checkValidationLayerSupport(){
  uint32_t layerCount;
  vkEnumerateInstanceLayerProperties(&layerCount);
  vkEnumerateInstanceLayerProperties(&layerCount,availableLayers.data());
  return false;
}


VkInstance vulk_instance;

const uint32_t WIDTH=800;
const uint32_t HEIGHT=600;
uint32_t glfwExtensionCount=0;
const char** glfwExtensions;

int vern1;
int vern2;
int vern3;

void win_init(){
  // Tells GLFW to not create an OpenGL context
  glfwWindowHint(GLFW_CLIENT_API,GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);
}



/*uint graphics_start(){
  win_init();
  vulk_init();
  return 0;
}*/

/*
 *  The Vulkan Procedure can be spun off into it's own process.
 **/
/*void vulk_proc_init(void *Yin){
  vulk_run();
  return NULL;
}*/
#endif
#endif
