//
//  ShaderNode.h
//  CocosEffect
//
//  Created by Nguyen Giang Chau on 7/30/15.
//
//

#ifndef __CocosEffect__ShaderNode__
#define __CocosEffect__ShaderNode__

#include <cocos2d.h>
#include <vector>
#include "RenderTexture.h"

USING_NS_CC;

class ShaderNode : public Node
{
public:
    ShaderNode();
    ~ShaderNode();
    virtual bool initWithWH(float w, float h);
    virtual void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags);
    virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
    virtual void setContentSize(const Size& contentSize);
    
    void saveTexture(const std::string& filename);
    
    Texture2D* getTexture() { return _texture; }
    chaung::RenderTexture* getRenderer() { return _rendertTexture; }
    
    static ShaderNode* createWithWH(float w, float h);
protected:
    void updateRenderTexture();
    
    Texture2D* _texture;
    chaung::RenderTexture* _rendertTexture;
    CustomCommand _customCommand;
    std::vector<Point> _vertices;
    std::vector<Vec2> _texCoords;
};

#endif /* defined(__CocosEffect__ShaderNode__) */
