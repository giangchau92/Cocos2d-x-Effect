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

USING_NS_CC;

class ShaderNode : public Node
{
public:
    ShaderNode();
    ~ShaderNode();
    virtual bool init();
    virtual void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags);
    virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
    
    CREATE_FUNC(ShaderNode);
private:
    Texture2D* _texture;
    RenderTexture* _rendertTexture;
    CustomCommand _customCommand;
    std::vector<Point> _vertices;
    std::vector<Vec2> _texCoords;
};

#endif /* defined(__CocosEffect__ShaderNode__) */
