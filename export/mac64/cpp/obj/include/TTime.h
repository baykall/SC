#ifndef INCLUDED_TTime
#define INCLUDED_TTime

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(MMoment)
HX_DECLARE_CLASS0(TTime)


class HXCPP_CLASS_ATTRIBUTES  TTime_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TTime_obj OBJ_;
		TTime_obj();
		Void __construct(int d,::String m,int y,int p);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< TTime_obj > __new(int d,::String m,int y,int p);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~TTime_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TTime"); }

		int pace;
		int cpu_time;
		int day;
		int year;
		int month_no;
		::String month;
		int total_days;
		::String calendar_day;
		::MMoment mmoment;
		Array< ::String > months;
		Array< int > month_days;
		virtual Void update( );
		Dynamic update_dyn();

		virtual Void update_day( );
		Dynamic update_day_dyn();

		virtual ::String get_calendar_day( );
		Dynamic get_calendar_day_dyn();

};


#endif /* INCLUDED_TTime */ 
