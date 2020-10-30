#ifndef ALSAMI_VULKAN_GM_RENDERER_H
#define ALSAMI_VULKAN_GM_RENDERER_H

#include <stdlib.h>
#include "tarray.h"

/*
 *	This is the vulkan renderer. It integrates with X11 to make this vulkan instance.
 *	This takes 3D representations and rastorizes them
 *
 *	(oh god this is not gonna be fun)
 * */
// It won't hurt to use some namesapces
void vulkanlogger_alsami(unsigned int lgr_md, const char* lgr_msg);
void vulk_inst_create_mod();

// AlsGM Developers, PLEASE DON'T DO using namespace Renderer; WHATEVER YOU DO. Please don't do it
namespace Renderer{
	void init();
	void dinit();

  VkInstance        rederer_vulk_inst=nullptr;
  VkPhysicalDevice  a_gpu=nullptr;
  VkDevice a_device=nullptr;

  void InitInstance();
  void dInitInstance();
  
  void InitDevice();
  void dInitDevice();

	const VkInstance		getVulkanInstance() const;
	const VkPhysicalDevice		getVulkanPhysicalDevice() const;
	const VkDevice			getVulkanDevice() const;
	const VkQueue			getVulkanQueue() const;
	const uint32_t		&	getVulkanGraphicsQueueFamilyIndex const;
	const VkPhysicalDeviceProperties	&	GetVulkanPhysicalDeviceProperties() const;

	const VkInstance getVulkanInstance() const
	{
		return _instance;
	} const VkPhysicalDevice getVulkanPhysicalDevice() const{
    return a_gpu;
  } const VkDevice getVulkanDevice() const{
    return a_device;
  } const VkQueue getVulkanQueue() const{
    return _queue
  } const uint32_t getVulkanGraphicsQueueFamilyIndex() const{
    return _graphics_family_index;
  } const VkPhysicalDeviceProperties & GetVulkanPhysicalDeviceProperties() const {
    return _gpu_properties;
  }
  void InitInstance(){
    VkApplicationInfo vulk_rd_appinfo{};
    vulk_rd_appinfo.sType=VK_STRUCTURE_TYPE_APPLICATION_INFO;
    vulk_rd_appinfo.pApplicationInfo= "Alsami Game Engine - Vulkan";
    vulk_rd_appinfo.applicationVersion=VK_MAKE_VERSION(1,0,0);
    vulk_rd_appinfo.pEngineName="alsgm-vulk";
    vulk_rd_appinfo.engineVersion=VK_MAKE_VERSION(1,2,9);
    vulk_rd_appinfo.apiVersion=VK_API_VERSION;
    VkInstanceCreateInfo Renderer_Create_Info{};
    Renderer_Create_Info.sType        = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    Renderer_Create_Info.pApplicationInfo=&vulk_rd_appinfo;
    Renderer_Create_Info.vulk_alsappInfo();

    if(vkCreateInstance(&Renderer_Create_Info,nullptr,/*instance to return value to*/&rederer_vulk_inst)!=VK_SUCSESS) {
      APP_QUIT();
      vulkanlogger_alsami(NULL,"ERROR: FAILED TO CREATE VULKAN INSTANCE. THIS IS A PREVIEW BUILD. MORE DETAILED LOGGING WILL COME SOON");
    }
  }
  void dInitInstance(){
    VkDestroyInstance(rederer_vulk_inst,nullptr);
    rederer_vulk_inst = nullptr;
  }
  void InitDevice(){
    uint32_t gpu_count=0;
    vkEnumeratePhysicalDevices(rederer_vulk_inst,&gpu_count,nullptr);
    VkPhysicalDevice[15] gpu_list;
    vkEnumeratePhysicalDevices(rederer_vulk_inst, &gpu_count, &gpu_list);
    a_gpu=gpu_list[ 0 ];

    vkCreateDevice(,  ,nullptr,&a_device);
    
  }
  void init(){
    /*assign memory and initalize the vulan instance*/
    InitInstance();
  } void dinit(){
    /* You know the dirll, just clean up memory after everything is done*/
    dInitInstance();
  }
}

#endif