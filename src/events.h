#ifndef ALSGM_EVENT_HANDLER_H
#define ALSGM_EVENT_HANDLER_H
#include "ihdr.h"

/*
 *	TODO:
 *		Add Blocking events sometime
 *
 *	Events in this engine are buffered. This means that the event process is able to run while the game is still running. This is because The project designer (Sami Alameddine) Decided that the engine should prioritize runing rahter than accepting input.
 *
 * 	What this means:
 * 		The Event handling will be in a seperate process. Whenever the listner calls the event handler, The Event Handler will put that in a buffer that is in a for(;;) loop. When the action is registered, the corresponding functions will be called. 
 *
 *
 **/

/*Event Handler Boilerplate*/
/*Boilerplate sources should be in the README*/

enum class EventType{
  None=0,
  WindowClose, WindowResize,WindowFocus,WindowLostFocus,WindowMoved,		/*Window*/
  AppTick,AppUpdate,AppRender,
  KeyPressed,KeyReleased,
  MouseButtonPressed,MouseButtonReleased,MouseMoved,MouseScrolled
};

enum EventCategory{
  None=0,
  EventCategoryApplication 	=BIT(0),
  EventCategoryInput		=BIT(1),
  EventCategoryKeyboard		=BIT(2),
  EventCategoryMouse		=BIT(3),
  EventCategoryMouseButton	=BIT(4)
}
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType(){return EventType:##type;}\
	virtual EventType GetEventType() const override {return GetStaticType();}\
	virtual const char* GetName() const override {return #type;}
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}

class evnt{
	friend class evntdisptr;
public:
	virtual EventType GetEventTYpe() const=0;
	virtual const char* GetName() const=0;
	virtual int GetCategoryFlags() const=0;
	virtual char tstr() const=0;
	
	inline bool IsInCategory(EventCategory category){return GetCategoryFlags() & category;}
protected:
	bool m_Handled=flase;
}
/*Code Adapted From Hazel Engine (repo: https://github.com/TheCherno/Hazel*/
class evntdisptr{
	template<typename T>
	using EventFn=std::function<bool(T&)>;
public:
	bool Dispatch(EventFn<t> func) {
		if(m_Event.GetEventType()==T::GetStaticType()) {
			m_Event.m_Handled = func(*(T*);
			return true;
		}
	}
}
/*End of Hazel Module*/

#endif
