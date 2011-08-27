#define xCAT(A,B) A ## B
#define CAT(A,B) xCAT(A,B)
#undef TYPE
#define TYPE CAT(isl_,BASE)
#define xFN(TYPE,NAME) TYPE ## _ ## NAME
#define FN(TYPE,NAME) xFN(TYPE,NAME)

void FN(TYPE,dump)(__isl_keep TYPE *obj)
{
	isl_printer *p;

	if (!obj)
		return;
	p = isl_printer_to_file(FN(TYPE,get_ctx)(obj), stderr);
	p = FN(isl_printer_print,BASE)(p, obj);
	p = isl_printer_end_line(p);
	isl_printer_free(p);
}