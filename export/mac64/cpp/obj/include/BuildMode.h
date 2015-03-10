#ifndef INCLUDED_BuildMode
#define INCLUDED_BuildMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(BuildMode)


class BuildMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef BuildMode_obj OBJ_;

	public:
		BuildMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("BuildMode"); }
		::String __ToString() const { return HX_CSTRING("BuildMode.") + tag; }

		static ::BuildMode None;
		static inline ::BuildMode None_dyn() { return None; }
		static ::BuildMode WheatFarm;
		static inline ::BuildMode WheatFarm_dyn() { return WheatFarm; }
};


#endif /* INCLUDED_BuildMode */ 
