/* Coded By    : Daniel Herman Shmulyan
   Version     : 0.1
   Description : Global defines. 
*/

#if !defined(GLOBALPREDEFINES_09FJ17FB3N59SGFOL6H7H7KJD3487_IINC)
#define GLOBALPREDEFINES_09FJ17FB3N59SGFOL6H7H7KJD3487_IINC

/****************************************************************************/
// Includes

/******************************** Constant Defines ***********************************/

#define IPE_DEFAULT_IMAGE_FILE   "------"
#define ARC_STRING_LENGTH  (1024)

/******************************** Macros Defines ***********************************/

// ----------------------------------------------------------
// integer to boolean conversion
#define __INT_2_BOOL(a)  ((a>0)?true:false)

// ----------------------------------------------------------
// String copy with protection against buffer overflow (by truncating suffix)
inline void safeStrCpy_(char* dst, const char* src, int dstSize){
	int i = 0;
	
	// Verify that source is not NULL
	if (src)
	   for (; i < dstSize-1; *(dst++) = src[i++]);		
	*dst = '\0';
}
#define safeStrBufCpy(dst,src)  safeStrCpy_(dst,src,sizeof(dst)) 

/****************************************************************************/

typedef struct _tNoun{
	_bstr_t heb;
	//char rus [ARC_STRING_LENGTH]; 
	CString rus;
} tNoun;

/*typedef struct _tWho{
	char rus [ARC_STRING_LENGTH]; 
	char heb [ARC_STRING_LENGTH];
} tWho;*/



#endif // #define GLOBALPREDEFINES_09FJ17FB3N59SGFOL6H7H7KJD3487_IINC

/****************************************************************************/
// EOF.
