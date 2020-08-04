#include "File.h"

//pxtnDescriptor::r
int ReadFromFile(void *p, size_t size, int num, PixFile* _p_desc)
{
  int i; // [sp+0h] [bp-4h]@5

  if ( *&_p_desc->type )
  {
    if ( fread(p, size, num, _p_desc->fp) != num )
      return 0;
  }
  else
  {
    for ( i = 0; i < num; ++i )
    {
      if ( (size + _p_desc->bytesRead) > _p_desc->size )
        return 0;
      memcpy(p + i, _p_desc->res + _p_desc->bytesRead, size);
      _p_desc->bytesRead += size;
    }
  }
  return 1;
}