#ifndef CVALUETYPE_HPP
#define CVALUETYPE_HPP

#include "CStrongTyped.hpp" 

template <typename T>
class CReferenceType : public CStrongTyped
{
	public:

		static const char * const TYPE_ID;

		// Default Constructor
		CReferenceType();

		// setter
		CReferenceType(const CTypedVariant & var);
		CReferenceType(const CStrongTyped & var);
		CReferenceType(const CReferenceType & var);

		CReferenceType(T val);
		CReferenceType & operator = (T val);
		void set(T val);

		// getter
		operator T ();
		T get();

	protected:

	private:

};

typedef CReferenceType<int> CInt;
typedef CReferenceType<unsigned int> CUInt;
typedef CReferenceType<short> CShort;
typedef CReferenceType<unsigned short> CUShort;
typedef CReferenceType<char> CChar;
typedef CReferenceType<unsigned char> CUChar;
typedef CReferenceType<float> CFloat;
typedef CReferenceType<double> CDouble;
typedef CReferenceType<bool> CBool;

#endif
