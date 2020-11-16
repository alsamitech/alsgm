#ifndef ALSAMI_VULKAN_GM_RENDERER_H
#define ALSAMI_VULKAN_GM_RENDERER_H

#include <stdlib.h>
//#include "tarray.h"

/*
 *	This is the vulkan renderer. It integrates with X11 to make this vulkan instance.
 *	This takes 3D representations and rastorizes them
 *
 *	(oh god this is not gonna be fun)
 * */
// It won't hurt to use some namespaces
void vulkanlogger_alsami(unsigned int lgr_md, const char* lgr_msg);
void vulk_inst_create_mod();

// AlsGM Developers, PLEASE DON'T DO using namespace Renderer; WHATEVER YOU DO. Please don't do it
namespace Renderer{
	void init();
	void dinit();

  VkInstance        rederer_vulk_inst=nullptr;
  VkPhysicalDevice  a_gpu=nullptr;
  VkDevice          a_device=nullptr;
  uint32_t          vulk_graphics_family_index;

  void InitInstance();
  void dInitInstance();

  void InitDevice();
  void dInitDevice();

	/*const VkInstance		getVulkanInstance() const;
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
  }*/
  void InitInstance(){
    VkApplicationInfo vulk_rd_appinfo{};
    vulk_rd_appinfo.sType=VK_STRUCTURE_TYPE_APPLICATION_INFO;
//    vulk_rd_appinfo.pApplicationInfo= "Alsami Game Engine - Vulkan";
    vulk_rd_appinfo.applicationVersion=VK_MAKE_VERSION(1,0,0);
    vulk_rd_appinfo.pEngineName="alsgm-vulk";
    vulk_rd_appinfo.engineVersion=VK_MAKE_VERSION(1,4,0);
    vulk_rd_appinfo.apiVersion=VK_API_VERSION_1_1;
    VkInstanceCreateInfo Renderer_Create_Info{};
    Renderer_Create_Info.sType        = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    Renderer_Create_Info.pApplicationInfo=&vulk_rd_appinfo;
    //Renderer_Create_Info.vulk_alsappInfo();

    if(vkCreateInstance(&Renderer_Create_Info,nullptr,/*instance to return value to*/&rederer_vulk_inst)!=VK_SUCCESS) {
      APP_QUIT();
      vulkanlogger_alsami(NULL,"ERROR: FAILED TO CREATE VULKAN INSTANCE. THIS IS A PREVIEW BUILD. MORE DETAILED LOGGING WILL COME SOON");
    }
  }
  void dInitInstance(){
    vkDestroyInstance(rederer_vulk_inst,nullptr);
    rederer_vulk_inst = nullptr;
  }
  void InitDevice(){
    {
        uint32_t gpu_count=0;
        vkEnumeratePhysicalDevices(rederer_vulk_inst,&gpu_count,nullptr);
        VkPhysicalDevice gpu_list[13];
        vkEnumeratePhysicalDevices(rederer_vulk_inst, &gpu_count, gpu_list);
        a_gpu=gpu_list[ 0 ];
    }

    {
        // this instance is created to ask vulkan what kind of families does it have
        uint32_t family_count=0;
        // Gets us how many families are there in this GPU
        vkGetPhysicalDeviceQueueFamilyProperties(a_gpu, /*uint32_t*/&family_count,nullptr);
        VkQueueFamilyProperties* family_property_list   =   malloc((sizeof((VkQueueFamilyProperties) * family_count));
        vkGetPhysicalDeviceQueueFamilyProperties(a_gpu, &family_count, family_property_list);

        // loops through the Queue families list and goes through every single one of the queue families and check which one supports the traffics bit
        bool QFound=false;
        for(uint32_t f_i=0< family_count;f_i++){
            if(family_property_list[f_i].queueFlags & VK_QUEUE_GRAPHICS_BIT){
                QFound=true;
                vulk_graphics_family_index=f_i;
            }
        } if(!QFound){
            // should print out:
            // [AlsGM RenderC] ERROR: AlsGM could not find a queue family supporting graphics
            // and tan try to resolve the issue
            exit(1);
        }
    }

    /*
     *  the graphics queue stuff (oh boy is this not going to be fun)
     **/

    // malloc so we can free this later
    float* queue_priorities=(float *) malloc(sizeof(float)*1);
    queue_priorities[1]=1.0f;

    VkDeviceQueueCreateInfo dq_cinfo { };
    dq_cinfo.sType                      = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    // In the GPU, there are queue families and those families different kinds of things. You need to select one of these queue families and than you need to tell Vulkan how many queues in that family you want to use
    // In the DeviceCreateInfo Structure we are going to introduce one QueueCreateInfo Structure. and in this structure, we are going to use one queue of one family index.
    // We need to figure out (for this structure), which family we are going to use
    dq_cinfo.queueFamilyIndex           = vulk_graphics_family_index;
    dq_cinfo.queueCount                 =1;
    // pQueuePriorities is a list of floats
    dq_cinfo.pQueuePriorities           =queue_priorities;

    VkDeviceCreateInfo als_d_cinfo{ };
    als_d_cinfo.sType           = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    als_d_cinfo.queueCreateInfoCount    =1;
    als_d_cinfo.pQueueCreatePos         = &dq_cinfo;

    vkCreateDevice(a_gpu,&als_d_cinfo,nullptr,&a_device);

  }
  void dInitDevice(){
    vkDestroyDevice(a_device, nullptr);
    a_device=nullptr;
  }
  void init(){
    /*assign memory and initalize the vulkan instance*/
    InitInstance();
  } void dinit(){
    /* You know the drill, just clean up memory after everything is done*/
    dInitInstance();
  }
}

#endif
