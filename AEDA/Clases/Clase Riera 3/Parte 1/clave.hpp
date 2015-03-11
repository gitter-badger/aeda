#pragma once

#define CLAVE_MAX_SZ 10

class clave_t
{
private:
	int* clave_;
public:
	clave_t(void);
	virtual ~clave_t(void);
	virtual void generarte_clave(void)=0;
	bool less_than(const clave_t* k);
};