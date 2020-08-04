#include "File.h"

//pxtnDescriptor::r
bool ReadFromFile(void *p, int size, int num, FILE* _p_desc)
{
  int i;

  if ( _p_desc->_ptr )
  {
    if ( fread(p, size, num, (FILE *)_p_desc->_cnt) != num )
      return 0;
  }
  else
  {
    for ( i = 0; i < num; ++i )
    {
      if ( (signed int)(size + _p_desc->_flag) > _p_desc->_file )
        return 0;
      memcpy((char *)p + i, &_p_desc->_base[_p_desc->_flag], size);
      _p_desc->_flag += size;
    }
  }
  return 1;
}

