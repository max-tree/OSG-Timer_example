#ifndef SPHEREUPDATECALLBACK_H
#define SPHEREUPDATECALLBACK_H
#include <osg/NodeCallback>

class SphereUpdateCallback: public osg::NodeCallback
{
public:
    SphereUpdateCallback();
    void operator()(osg::Node* node, osg::NodeVisitor* nv);

protected:
    bool mUp{true};
    unsigned int mCount{0};
    double mScaleStep{1.0/30.0};
};


#endif // SPHEREUPDATECALLBACK_H
