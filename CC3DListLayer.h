//
//  CCTextLayer.h
//  CCTextLayer
//
//  Created by wangbin on 13-1-9.
//
//

#ifndef __CC3DListLayer__CCTextLayer__
#define __CC3DListLayer__CCTextLayer__

#include <iostream>
#include "CCCutTouchLayer.h"
#include "cocos2d.h"
#include "CCScrollLayer.h"
#include "CCButton.h"
USING_NS_CC;

class  CC3DListLayer : public CCCutTouchLayer
{
public:
    
    enum ListType
    {
        eListType_Unknown =0,
        eListType_HalfEllipse =1,
        eListType_CoverFlow   =2,
        eListType_Ellipse     =3,
        eListType_Line        =4,
        
    };
    CC3DListLayer();
  virtual ~CC3DListLayer();
	CREATE_FUNC(CC3DListLayer);
    
    static CC3DListLayer*   create(const ccColor4B& color, GLfloat width, GLfloat height);
    virtual bool            initWithColor(const ccColor4B& color, GLfloat w, GLfloat h);
    
    
    void                    initDataCoverFlow(float fSpaceX,CCSize itemSize,CCArray* pArray,bool bFlipY);
    void                    initDataLine(float fSpaceX,float fSpaceY,CCSize itemSize,CCArray* pArray,bool bFlipY);
    void                    initDataHalfEllipse(float fSpaceX,float fEllipseA,float fEllipseB,CCSize itemSize,CCArray* pArray,bool bFlipY);
    void                    initDataEllipse(float fSpaceX,CCSize itemSize,CCArray* pArray,bool bFlipY);


protected:
    void                    refreshItem();
    void                    actionMove();
    void                    moveToCenter(CCButton* pButton,bool bAction);
    void                    refreshItemCoverFlow();
    void                    refreshItemHalfEllipse();
    void                    refreshItemEllipse();
    void                    refreshItemLine();

    void                    clickButton(CCButton* pButton);
    
    void                    decelerateEnd();
    void                    actionEnd();
    void                    decelerateMove();
private:
    CCArray*                m_pButtonArray;
    CCScrollLayer*          m_pScrollLayer;
    float                   m_fSpaceX;
    float                   m_fOriginSpaceX;
    CCSize                  m_itemSize;
    ListType                m_eListType;
    CCButton*               m_pSelectedButton;
    
    float                   m_fEllipseA;
    float                   m_fEllipseB;
};

#endif /* defined(__CC3DListLayer__CCTextLayer__) */
