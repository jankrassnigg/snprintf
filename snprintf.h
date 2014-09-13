/*
The MIT License (MIT)

Copyright (c) 2014 Jan Krassnigg

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

/// This is a custom implementation of snprintf, which makes it reliably portable across different platforms.
/// It uses standard C++ 98.
///
/// The major difference to "standard" sprintf is, that you can specify the size of the output buffer.
/// This is often known under the name "snprintf", however, this function seems not to be standardized and 
/// implementations often vary in what their return value means. Ie. some will just return how much they have
/// written, not how much they could have written. This makes it difficult to implement a function that allocates
/// enough room to format the entire string.
/// Also different implementation vary in how exactly they format certain things, e.g. floating point values.
/// Some implementations ignore the precision specifiers and most implementations do not handle NaN and Infinity
/// properly.
/// This can be annoying when working on multiple platforms but identical output is desired.
/// Therefore a custom implementation can solve such issues.


/// \brief Creates a formated string in szDst. uiDstSize defines how many bytes szDst can hold. 
///
/// Formatting details can be found here: http://www.cplusplus.com/reference/clibrary/cstdio/sprintf
///
/// Returns the number of bytes that would have been required to output the entire string (excluding the \0 terminator).\n
/// Returns -1 if an error occurred. In this case it might also write a more detailed error message to the destination string itself.
/// szDst may be nullptr.\n
/// uiDstSize may be zero.\n
/// This can be used to query how much storage is required, then allocate it and call snprintf again to fill it.\n
/// Formatting works exactly like printf, except that it additionally supports outputting binary with the 'b' modifier and it will
/// output float NaN and Infinity as proper text.
int snprintf (char* szOutputBuffer, unsigned int uiBufferSize, const char* szFormat, ...);

/// \brief Same as snprintf() but takes a va_list for the arguments.
int vsnprintf(char* szOutputBuffer, unsigned int uiBufferSize, const char* szFormat, va_list args0);



