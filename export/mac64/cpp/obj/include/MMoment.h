#ifndef INCLUDED_MMoment
#define INCLUDED_MMoment

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(MMoment)


class MMoment_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef MMoment_obj OBJ_;

	public:
		MMoment_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("MMoment"); }
		::String __ToString() const { return HX_CSTRING("MMoment.") + tag; }

		static ::MMoment NewDay;
		static inline ::MMoment NewDay_dyn() { return NewDay; }
		static ::MMoment OngoingDay;
		static inline ::MMoment OngoingDay_dyn() { return OngoingDay; }
};


#endif /* INCLUDED_MMoment */ 
