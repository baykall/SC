#ifndef INCLUDED_City
#define INCLUDED_City

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(City)


class HXCPP_CLASS_ATTRIBUTES  City_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef City_obj OBJ_;
		City_obj();
		Void __construct(::String n,int c_x,int c_y,Dynamic p);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< City_obj > __new(::String n,int c_x,int c_y,Dynamic p);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~City_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("City"); }

		::String name;
		int coordinate_x;
		int coordinate_y;
		int label_coordinate_x;
		int label_coordinate_y;
		int population_total;
		Array< int > population;
};


#endif /* INCLUDED_City */ 
