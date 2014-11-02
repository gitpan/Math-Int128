
/*
 * c_api.h - This file is in the public domain
 * Author: Salvador Fandino <sfandino@yahoo.com>
 *
 * Generated on: 2013-09-06 20:42:10
 * Math::Int128 version: 0.13
 * Module::CAPIMaker version: 0.02
 */

#if !defined (C_API_H_INCLUDED)
#define C_API_H_INCLUDED

static void
init_c_api(pTHX) {
    HV *hv = get_hv("Math::Int128::C_API", TRUE|GV_ADDMULTI);
    hv_store(hv, "min_version", 11, newSViv(1), 0);
    hv_store(hv, "max_version", 11, newSViv(1), 0);
    hv_store(hv, "SvI128", 6, newSViv(PTR2IV(&SvI128)), 0);
    hv_store(hv, "SvI128OK", 8, newSViv(PTR2IV(&SvI128OK)), 0);
    hv_store(hv, "SvU128", 6, newSViv(PTR2IV(&SvU128)), 0);
    hv_store(hv, "SvU128OK", 8, newSViv(PTR2IV(&SvU128OK)), 0);
    hv_store(hv, "newSVi128", 9, newSViv(PTR2IV(&newSVi128)), 0);
    hv_store(hv, "newSVu128", 9, newSViv(PTR2IV(&newSVu128)), 0);

}

#define INIT_C_API init_c_api(aTHX)

#endif
