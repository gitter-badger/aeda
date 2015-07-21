//Division

natural_t operator/(const natural_t b) const
{
	unsigned int result = (b.valor != 0) ? Valor/b.Valor: 0;
	return result;
}