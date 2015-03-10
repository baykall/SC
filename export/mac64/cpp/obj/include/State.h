#ifndef INCLUDED_State
#define INCLUDED_State

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(State)


class State_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef State_obj OBJ_;

	public:
		State_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("State"); }
		::String __ToString() const { return HX_CSTRING("State.") + tag; }

		static ::State Paused;
		static inline ::State Paused_dyn() { return Paused; }
		static ::State Running;
		static inline ::State Running_dyn() { return Running; }
};


#endif /* INCLUDED_State */ 
