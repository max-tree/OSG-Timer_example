#include "SphereUpdateCallback.h"
#include <osg/PositionAttitudeTransform>
#include <osg/NodeVisitor>

SphereUpdateCallback::SphereUpdateCallback()
{

}

void SphereUpdateCallback::operator()(osg::Node* node, osg::NodeVisitor* nv)
{
    if(mUp)
        mCount++;
    else
        mCount--;

    osg::Vec3d scaleFactor(mScaleStep*mCount+1.0, 1.0, 1.0);
    osg::PositionAttitudeTransform *pat = dynamic_cast<osg::PositionAttitudeTransform *> (node);
    pat->setScale(scaleFactor);

    traverse(node, nv);

    if(mCount==30 || mCount==0)
        mUp=!mUp;
}
