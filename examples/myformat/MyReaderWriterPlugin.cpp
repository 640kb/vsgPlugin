
#include "MyReaderWriter.h"
#include <vsg/io/Options.h>

extern "C"
{
#if defined(_WIN32)
__declspec(dllexport)
#endif
// This symbol is what the application will look up via dlsym
void vsgRegisterReaderWriters(vsg::Options& options)
{
    options.add(myformat::MyReaderWriter::create());
}

}
