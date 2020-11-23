#include "core.h"
#include "vulk/renderer.h"

using namespace Renderer;

void *STRT(void *ptr) {
  WRT_TO_FL("TEST: TEST");
  FRMT_LOG("BOOTED TO ENTRY POINT","This is a test","CRITICAL","DONE",1);
  FRMT_LOG("MODIFY TEST","OFFICIAL ALSGM TEST PROGRAM","DEBUGGING", "SUCSESS",1);

  init();

  VkDevice dev_x=a_device;

  VkCommandPool vulk_cmpl;
  VkCommandPoolCreateInfo test_cinfo{ };
  test_cinfo.sType                      =VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
  test_cinfo.queueFamilyIndex           =vulk_graphics_family_index;
  // to create command buffers, you need a pool
  test_cinfo.flags                      =VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
  vkCreateCommandPool(dev_x, &test_cinfo, nullptr, &vulk_cmpl);


  // de-initallize stuff
  dinit();

  return NULL;
}
