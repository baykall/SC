#include <hxcpp.h>

#ifndef INCLUDED_MMoment
#include <MMoment.h>
#endif

::MMoment MMoment_obj::NewDay;

::MMoment MMoment_obj::OngoingDay;

HX_DEFINE_CREATE_ENUM(MMoment_obj)

int MMoment_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("NewDay")) return 0;
	if (inName==HX_CSTRING("OngoingDay")) return 1;
	return super::__FindIndex(inName);
}

int MMoment_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("NewDay")) return 0;
	if (inName==HX_CSTRING("OngoingDay")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic MMoment_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("NewDay")) return NewDay;
	if (inName==HX_CSTRING("OngoingDay")) return OngoingDay;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("NewDay"),
	HX_CSTRING("OngoingDay"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MMoment_obj::NewDay,"NewDay");
	HX_MARK_MEMBER_NAME(MMoment_obj::OngoingDay,"OngoingDay");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MMoment_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(MMoment_obj::NewDay,"NewDay");
	HX_VISIT_MEMBER_NAME(MMoment_obj::OngoingDay,"OngoingDay");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class MMoment_obj::__mClass;

Dynamic __Create_MMoment_obj() { return new MMoment_obj; }

void MMoment_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("MMoment"), hx::TCanCast< MMoment_obj >,sStaticFields,sMemberFields,
	&__Create_MMoment_obj, &__Create,
	&super::__SGetClass(), &CreateMMoment_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void MMoment_obj::__boot()
{
hx::Static(NewDay) = hx::CreateEnum< MMoment_obj >(HX_CSTRING("NewDay"),0);
hx::Static(OngoingDay) = hx::CreateEnum< MMoment_obj >(HX_CSTRING("OngoingDay"),1);
}


