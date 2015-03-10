#include <hxcpp.h>

#ifndef INCLUDED_BuildMode
#include <BuildMode.h>
#endif

::BuildMode BuildMode_obj::None;

::BuildMode BuildMode_obj::WheatFarm;

HX_DEFINE_CREATE_ENUM(BuildMode_obj)

int BuildMode_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("None")) return 0;
	if (inName==HX_CSTRING("WheatFarm")) return 1;
	return super::__FindIndex(inName);
}

int BuildMode_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("None")) return 0;
	if (inName==HX_CSTRING("WheatFarm")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic BuildMode_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("None")) return None;
	if (inName==HX_CSTRING("WheatFarm")) return WheatFarm;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("None"),
	HX_CSTRING("WheatFarm"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BuildMode_obj::None,"None");
	HX_MARK_MEMBER_NAME(BuildMode_obj::WheatFarm,"WheatFarm");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BuildMode_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BuildMode_obj::None,"None");
	HX_VISIT_MEMBER_NAME(BuildMode_obj::WheatFarm,"WheatFarm");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class BuildMode_obj::__mClass;

Dynamic __Create_BuildMode_obj() { return new BuildMode_obj; }

void BuildMode_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("BuildMode"), hx::TCanCast< BuildMode_obj >,sStaticFields,sMemberFields,
	&__Create_BuildMode_obj, &__Create,
	&super::__SGetClass(), &CreateBuildMode_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void BuildMode_obj::__boot()
{
hx::Static(None) = hx::CreateEnum< BuildMode_obj >(HX_CSTRING("None"),0);
hx::Static(WheatFarm) = hx::CreateEnum< BuildMode_obj >(HX_CSTRING("WheatFarm"),1);
}


