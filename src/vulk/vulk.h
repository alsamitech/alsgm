#ifndef ALSAMI_VULKAN_MAIN_HEADER_OPENGL
#define ALSAMI_VULKAN_MAIN_HEADER_OPENGL

#define ALS_RUNTIME_ERROR 50


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

 FILE *vulk_filelgr;

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

bool checkValidationLayerSupport(){
  uint32_t layerCount;
  vkEnumerateInstanceLayerProperties(&layerCount);
  vkEnumerateInstanceLayerProperties(&layerCount,availableLayers.data());
  return false;
}

void vulkanlogger_alsami(unsigned int lgr_md, const char* lgr_msg){
   
    vulk_filelgr=fopen("vulk_runtime.als.log", w+);

    fprintf(vulk_filelgr, "%s\n", lgr_msg);

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
        glgwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);


}

void vulk_inst_create(){
  VkApplicationInfo vulk_appinfo{};
  vulk_appinfo.sType=VK_STRUCTURE_TYPE_APPLICATION_INFO;
  vulk_appinfo.pApplicationInfo= vulk_als_appnm;
  appInfo.applicationVersion=VK_MAKE_VERSION(vern1,vern2,vern3);
  appInfo.pEngineName="alsgm-vulk";
  appInfo.engineVersion=VK_MAKE_VERSION(1,2,9);
  appInfo.apiVersion=VK_API_VERSION_1_0;
  vkInstanceCreateInfo vulk_cinfo{};
  vulk_cinfo.sType=VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  vulk_cinfo.pApplicationInfo=&vulk_appinfo;
  glfwExtensions=glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
  vulk_cinfo.enabledExtensionCount=glfwExtensionCount;
  vulk_cinfo=ppEnabledExtensionNames=glfwExtensions;
  vulk_cinfo.enabledLayerCount=0;
  // not needed until I screw something up really bad
  //VkResult result=vkCreateInstance(vkCreateInstance(&vulk_cinfo,nullptr,&vulk_instance));
  if(vkCreateInstance(vkCreateInstance(&vulk_cinfo,nullptr,&vulk_instance))!=VK_SUCSESS) {
    vulkanlogger_alsami(ALS_RUNTIME_ERROR,"Failed to create instance!");
  }
  
}

void setupDebugMessenger(){
	if(!enableValidationLayers)return;
}

void vulk_init(){
  vulk_inst_create();

  // Oh God it's time to do the debug stuff (nice)
  SETUP_DBG_MSNGR();
}

void vulk_wlp(){
  while(!glfwWindowShouldClose(window)){
    glfwPollEvents();
  }
}

void vulk_cleanup(){
  vkDestroyInstance(vulk_instance, nullptr);
  glfwDestroyWindow(window);
  glfwTerminate();
  fclose(vulk_filelgr);
}


/*
 * Initial vulkan drawing step
 **/
void vulk_run(){
        win_init();
        vulk_init();
        vulk_wlp();
        vulk_cleanup();
        
}       


/*
 *  The Vulkan Procedure Must be spun off into it's own process.
 **/
void vulk_proc_init(void *Yin){
  vulk_run();
  return NULL;
}

#endif
