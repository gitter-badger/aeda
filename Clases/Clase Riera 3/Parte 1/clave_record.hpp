#pragma once
#include "clave.hpp"
#include "record.hpp"

class clave_record_t:public clave_t
{
private:
	record_t* record_ptr_;
public:
	clave_record_t(record_t* r);
	virtual ~clave_record_t(void);
};