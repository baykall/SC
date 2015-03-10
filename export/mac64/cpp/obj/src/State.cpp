#include <hxcpp.h>

#ifndef INCLUDED_State
#include <State.h>
#endif

::State State_obj::Paused;

::State State_obj::Running;

HX_DEFINE_CREATE_ENUM(State_obj)

int State_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("Paused")) return 0;
	if (inName==HX_CSTRING("Running")) return 1;
	return super::__FindIndex(inName);
}

int State_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("Paused")) return 0;
	if (inName==HX_CSTRING("Running")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic State_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("Paused")) return Paused;
	if (inName==HX_CSTRING("Running")) return Running;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("Paused"),
	HX_CSTRING("Running"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(State_obj::Paused,"Paused");
	HX_MARK_MEMBER_NAME(State_obj::Running,"Running");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(State_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(State_obj::Paused,"Paused");
	HX_VISIT_MEMBER_NAME(State_obj::Running,"Running");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class State_obj::__mClass;

Dynamic __Create_State_obj() { return new State_obj; }

void State_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("State"), hx::TCanCast< State_obj >,sStaticFields,sMemberFields,
	&__Create_State_obj, &__Create,
	&super::__SGetClass(), &CreateState_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void State_obj::__boot()
{
hx::Static(Paused) = hx::CreateEnum< State_obj >(HX_CSTRING("Paused"),0);
hx::Static(Running) = hx::CreateEnum< State_obj >(HX_CSTRING("Running"),1);
}


