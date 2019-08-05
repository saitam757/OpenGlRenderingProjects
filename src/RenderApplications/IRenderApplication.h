#ifndef IRENDERAPPLICATION_H__
#define IRENDERAPPLICATION_H__

namespace OpenGlApplication
{
class IRenderApplication
{
public:
    virtual ~IRenderApplication() {}

    virtual void Init() = 0;

    virtual void DoRender() = 0;

    virtual void SetKey(int key) = 0;
};
}

#endif //IRENDERAPPLICATION_H__
