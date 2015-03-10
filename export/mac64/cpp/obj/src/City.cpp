#include <hxcpp.h>

#ifndef INCLUDED_City
#include <City.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif

Void City_obj::__construct(::String n,int c_x,int c_y,Dynamic p)
{
HX_STACK_FRAME("City","new",0x321f403d,"City.new","City.hx",12,0xf83055d3)
HX_STACK_THIS(this)
HX_STACK_ARG(n,"n")
HX_STACK_ARG(c_x,"c_x")
HX_STACK_ARG(c_y,"c_y")
HX_STACK_ARG(p,"p")
{
	HX_STACK_LINE(13)
	this->name = n;
	HX_STACK_LINE(14)
	this->coordinate_x = c_x;
	HX_STACK_LINE(15)
	this->coordinate_y = c_y;
	HX_STACK_LINE(16)
	Array< int > _g = p->__Field(HX_CSTRING("copy"),true)();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(16)
	this->population = _g;
	HX_STACK_LINE(17)
	this->label_coordinate_x = (((c_x - (int)1)) * ::PlayState_obj::TILE_WIDTH);
	HX_STACK_LINE(18)
	this->label_coordinate_y = (((c_y + (int)1)) * ::PlayState_obj::TILE_WIDTH);
}
;
	return null();
}

//City_obj::~City_obj() { }

Dynamic City_obj::__CreateEmpty() { return  new City_obj; }
hx::ObjectPtr< City_obj > City_obj::__new(::String n,int c_x,int c_y,Dynamic p)
{  hx::ObjectPtr< City_obj > result = new City_obj();
	result->__construct(n,c_x,c_y,p);
	return result;}

Dynamic City_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< City_obj > result = new City_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}


City_obj::City_obj()
{
}

void City_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(City);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(coordinate_x,"coordinate_x");
	HX_MARK_MEMBER_NAME(coordinate_y,"coordinate_y");
	HX_MARK_MEMBER_NAME(label_coordinate_x,"label_coordinate_x");
	HX_MARK_MEMBER_NAME(label_coordinate_y,"label_coordinate_y");
	HX_MARK_MEMBER_NAME(population_total,"population_total");
	HX_MARK_MEMBER_NAME(population,"population");
	HX_MARK_END_CLASS();
}

void City_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(coordinate_x,"coordinate_x");
	HX_VISIT_MEMBER_NAME(coordinate_y,"coordinate_y");
	HX_VISIT_MEMBER_NAME(label_coordinate_x,"label_coordinate_x");
	HX_VISIT_MEMBER_NAME(label_coordinate_y,"label_coordinate_y");
	HX_VISIT_MEMBER_NAME(population_total,"population_total");
	HX_VISIT_MEMBER_NAME(population,"population");
}

Dynamic City_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"population") ) { return population; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"coordinate_x") ) { return coordinate_x; }
		if (HX_FIELD_EQ(inName,"coordinate_y") ) { return coordinate_y; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"population_total") ) { return population_total; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"label_coordinate_x") ) { return label_coordinate_x; }
		if (HX_FIELD_EQ(inName,"label_coordinate_y") ) { return label_coordinate_y; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic City_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"population") ) { population=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"coordinate_x") ) { coordinate_x=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"coordinate_y") ) { coordinate_y=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"population_total") ) { population_total=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"label_coordinate_x") ) { label_coordinate_x=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"label_coordinate_y") ) { label_coordinate_y=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void City_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("coordinate_x"));
	outFields->push(HX_CSTRING("coordinate_y"));
	outFields->push(HX_CSTRING("label_coordinate_x"));
	outFields->push(HX_CSTRING("label_coordinate_y"));
	outFields->push(HX_CSTRING("population_total"));
	outFields->push(HX_CSTRING("population"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(City_obj,name),HX_CSTRING("name")},
	{hx::fsInt,(int)offsetof(City_obj,coordinate_x),HX_CSTRING("coordinate_x")},
	{hx::fsInt,(int)offsetof(City_obj,coordinate_y),HX_CSTRING("coordinate_y")},
	{hx::fsInt,(int)offsetof(City_obj,label_coordinate_x),HX_CSTRING("label_coordinate_x")},
	{hx::fsInt,(int)offsetof(City_obj,label_coordinate_y),HX_CSTRING("label_coordinate_y")},
	{hx::fsInt,(int)offsetof(City_obj,population_total),HX_CSTRING("population_total")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(City_obj,population),HX_CSTRING("population")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("name"),
	HX_CSTRING("coordinate_x"),
	HX_CSTRING("coordinate_y"),
	HX_CSTRING("label_coordinate_x"),
	HX_CSTRING("label_coordinate_y"),
	HX_CSTRING("population_total"),
	HX_CSTRING("population"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(City_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(City_obj::__mClass,"__mClass");
};

#endif

Class City_obj::__mClass;

void City_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("City"), hx::TCanCast< City_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void City_obj::__boot()
{
}

