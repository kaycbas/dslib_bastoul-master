
template <class keyType, class valueType>		//item function implementations
Item<keyType, valueType>::Item()
{
	next = NULL;
	prev = NULL;
}

template <class keyType, class valueType>
keyType* Item<keyType, valueType>::get_key()
{
	return &key;
}

template <class keyType, class valueType>
valueType* Item<keyType, valueType>::get_value()
{
	return &value;
}
