#include <hxcpp.h>

#ifndef INCLUDED_MMoment
#include <MMoment.h>
#endif
#ifndef INCLUDED_TTime
#include <TTime.h>
#endif

Void TTime_obj::__construct(int d,::String m,int y,int p)
{
HX_STACK_FRAME("TTime","new",0xe52c27f3,"TTime.new","TTime.hx",8,0x6aa456dd)
HX_STACK_THIS(this)
HX_STACK_ARG(d,"d")
HX_STACK_ARG(m,"m")
HX_STACK_ARG(y,"y")
HX_STACK_ARG(p,"p")
{
	HX_STACK_LINE(20)
	this->month_days = Array_obj< int >::__new().Add((int)31).Add((int)28).Add((int)31).Add((int)30).Add((int)31).Add((int)30).Add((int)31).Add((int)31).Add((int)30).Add((int)31).Add((int)30).Add((int)31);
	HX_STACK_LINE(19)
	this->months = Array_obj< ::String >::__new().Add(HX_CSTRING("January")).Add(HX_CSTRING("February")).Add(HX_CSTRING("March")).Add(HX_CSTRING("April")).Add(HX_CSTRING("May")).Add(HX_CSTRING("June")).Add(HX_CSTRING("July")).Add(HX_CSTRING("August")).Add(HX_CSTRING("September")).Add(HX_CSTRING("October")).Add(HX_CSTRING("November")).Add(HX_CSTRING("December"));
	HX_STACK_LINE(23)
	this->day = d;
	HX_STACK_LINE(24)
	this->month = m;
	HX_STACK_LINE(25)
	this->year = y;
	HX_STACK_LINE(26)
	this->pace = p;
	HX_STACK_LINE(27)
	this->total_days = (int)0;
	HX_STACK_LINE(28)
	this->cpu_time = (int)0;
	HX_STACK_LINE(29)
	this->mmoment = ::MMoment_obj::NewDay;
	HX_STACK_LINE(30)
	{
		HX_STACK_LINE(30)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(30)
		while((true)){
			HX_STACK_LINE(30)
			if ((!(((_g < (int)11))))){
				HX_STACK_LINE(30)
				break;
			}
			HX_STACK_LINE(30)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(31)
			if (((m == this->months->__get(i)))){
				HX_STACK_LINE(32)
				this->month_no = i;
				HX_STACK_LINE(33)
				break;
			}
		}
	}
}
;
	return null();
}

//TTime_obj::~TTime_obj() { }

Dynamic TTime_obj::__CreateEmpty() { return  new TTime_obj; }
hx::ObjectPtr< TTime_obj > TTime_obj::__new(int d,::String m,int y,int p)
{  hx::ObjectPtr< TTime_obj > result = new TTime_obj();
	result->__construct(d,m,y,p);
	return result;}

Dynamic TTime_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TTime_obj > result = new TTime_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void TTime_obj::update( ){
{
		HX_STACK_FRAME("TTime","update",0x1be7ec56,"TTime.update","TTime.hx",38,0x6aa456dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(39)
		(this->cpu_time)++;
		HX_STACK_LINE(40)
		if (((hx::Mod(this->cpu_time,this->pace) == (int)0))){
			HX_STACK_LINE(41)
			this->update_day();
			HX_STACK_LINE(42)
			this->mmoment = ::MMoment_obj::NewDay;
		}
		else{
			HX_STACK_LINE(45)
			this->mmoment = ::MMoment_obj::OngoingDay;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TTime_obj,update,(void))

Void TTime_obj::update_day( ){
{
		HX_STACK_FRAME("TTime","update_day",0xefdb4ab3,"TTime.update_day","TTime.hx",48,0x6aa456dd)
		HX_STACK_THIS(this)
		HX_STACK_LINE(49)
		if (((bool((this->day == this->month_days->__get(this->month_no))) && bool((this->month_no == (int)11))))){
			HX_STACK_LINE(50)
			this->day = (int)1;
			HX_STACK_LINE(51)
			this->month_no = (int)0;
			HX_STACK_LINE(52)
			(this->year)++;
			HX_STACK_LINE(53)
			this->month = this->months->__get((int)0);
		}
		else{
			HX_STACK_LINE(55)
			if (((this->day >= this->month_days->__get(this->month_no)))){
				HX_STACK_LINE(56)
				if (((bool((bool((this->month_no == (int)1)) && bool((hx::Mod(this->year,(int)4) == (int)0)))) && bool((this->day == (int)28))))){
					HX_STACK_LINE(57)
					(this->day)++;
				}
				else{
					HX_STACK_LINE(60)
					this->day = (int)1;
					HX_STACK_LINE(61)
					(this->month_no)++;
					HX_STACK_LINE(62)
					this->month = this->months->__get(this->month_no);
				}
			}
			else{
				HX_STACK_LINE(66)
				(this->day)++;
			}
		}
		HX_STACK_LINE(68)
		(this->total_days)++;
		HX_STACK_LINE(69)
		::String _g = this->get_calendar_day();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(69)
		this->calendar_day = _g;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TTime_obj,update_day,(void))

::String TTime_obj::get_calendar_day( ){
	HX_STACK_FRAME("TTime","get_calendar_day",0xc10d2631,"TTime.get_calendar_day","TTime.hx",73,0x6aa456dd)
	HX_STACK_THIS(this)
	HX_STACK_LINE(73)
	return ((((this->day + HX_CSTRING(" ")) + this->month) + HX_CSTRING(" ")) + this->year);
}


HX_DEFINE_DYNAMIC_FUNC0(TTime_obj,get_calendar_day,return )


TTime_obj::TTime_obj()
{
}

void TTime_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TTime);
	HX_MARK_MEMBER_NAME(pace,"pace");
	HX_MARK_MEMBER_NAME(cpu_time,"cpu_time");
	HX_MARK_MEMBER_NAME(day,"day");
	HX_MARK_MEMBER_NAME(year,"year");
	HX_MARK_MEMBER_NAME(month_no,"month_no");
	HX_MARK_MEMBER_NAME(month,"month");
	HX_MARK_MEMBER_NAME(total_days,"total_days");
	HX_MARK_MEMBER_NAME(calendar_day,"calendar_day");
	HX_MARK_MEMBER_NAME(mmoment,"mmoment");
	HX_MARK_MEMBER_NAME(months,"months");
	HX_MARK_MEMBER_NAME(month_days,"month_days");
	HX_MARK_END_CLASS();
}

void TTime_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(pace,"pace");
	HX_VISIT_MEMBER_NAME(cpu_time,"cpu_time");
	HX_VISIT_MEMBER_NAME(day,"day");
	HX_VISIT_MEMBER_NAME(year,"year");
	HX_VISIT_MEMBER_NAME(month_no,"month_no");
	HX_VISIT_MEMBER_NAME(month,"month");
	HX_VISIT_MEMBER_NAME(total_days,"total_days");
	HX_VISIT_MEMBER_NAME(calendar_day,"calendar_day");
	HX_VISIT_MEMBER_NAME(mmoment,"mmoment");
	HX_VISIT_MEMBER_NAME(months,"months");
	HX_VISIT_MEMBER_NAME(month_days,"month_days");
}

Dynamic TTime_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"day") ) { return day; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"pace") ) { return pace; }
		if (HX_FIELD_EQ(inName,"year") ) { return year; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"month") ) { return month; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"months") ) { return months; }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mmoment") ) { return mmoment; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"cpu_time") ) { return cpu_time; }
		if (HX_FIELD_EQ(inName,"month_no") ) { return month_no; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"total_days") ) { return total_days; }
		if (HX_FIELD_EQ(inName,"month_days") ) { return month_days; }
		if (HX_FIELD_EQ(inName,"update_day") ) { return update_day_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"calendar_day") ) { return calendar_day; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"get_calendar_day") ) { return get_calendar_day_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TTime_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"day") ) { day=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"pace") ) { pace=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"year") ) { year=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"month") ) { month=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"months") ) { months=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mmoment") ) { mmoment=inValue.Cast< ::MMoment >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"cpu_time") ) { cpu_time=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"month_no") ) { month_no=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"total_days") ) { total_days=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"month_days") ) { month_days=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"calendar_day") ) { calendar_day=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TTime_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("pace"));
	outFields->push(HX_CSTRING("cpu_time"));
	outFields->push(HX_CSTRING("day"));
	outFields->push(HX_CSTRING("year"));
	outFields->push(HX_CSTRING("month_no"));
	outFields->push(HX_CSTRING("month"));
	outFields->push(HX_CSTRING("total_days"));
	outFields->push(HX_CSTRING("calendar_day"));
	outFields->push(HX_CSTRING("mmoment"));
	outFields->push(HX_CSTRING("months"));
	outFields->push(HX_CSTRING("month_days"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(TTime_obj,pace),HX_CSTRING("pace")},
	{hx::fsInt,(int)offsetof(TTime_obj,cpu_time),HX_CSTRING("cpu_time")},
	{hx::fsInt,(int)offsetof(TTime_obj,day),HX_CSTRING("day")},
	{hx::fsInt,(int)offsetof(TTime_obj,year),HX_CSTRING("year")},
	{hx::fsInt,(int)offsetof(TTime_obj,month_no),HX_CSTRING("month_no")},
	{hx::fsString,(int)offsetof(TTime_obj,month),HX_CSTRING("month")},
	{hx::fsInt,(int)offsetof(TTime_obj,total_days),HX_CSTRING("total_days")},
	{hx::fsString,(int)offsetof(TTime_obj,calendar_day),HX_CSTRING("calendar_day")},
	{hx::fsObject /*::MMoment*/ ,(int)offsetof(TTime_obj,mmoment),HX_CSTRING("mmoment")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(TTime_obj,months),HX_CSTRING("months")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(TTime_obj,month_days),HX_CSTRING("month_days")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("pace"),
	HX_CSTRING("cpu_time"),
	HX_CSTRING("day"),
	HX_CSTRING("year"),
	HX_CSTRING("month_no"),
	HX_CSTRING("month"),
	HX_CSTRING("total_days"),
	HX_CSTRING("calendar_day"),
	HX_CSTRING("mmoment"),
	HX_CSTRING("months"),
	HX_CSTRING("month_days"),
	HX_CSTRING("update"),
	HX_CSTRING("update_day"),
	HX_CSTRING("get_calendar_day"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TTime_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TTime_obj::__mClass,"__mClass");
};

#endif

Class TTime_obj::__mClass;

void TTime_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("TTime"), hx::TCanCast< TTime_obj> ,sStaticFields,sMemberFields,
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

void TTime_obj::__boot()
{
}

