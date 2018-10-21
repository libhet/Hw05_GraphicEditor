#ifndef HW05_GRAPHICEDITOR_GRAPHICSVIEW_H
#define HW05_GRAPHICEDITOR_GRAPHICSVIEW_H

#include "graphics_model.h"

class GraphicsDocumentView {   //View
private:
    GraphicsDocumentPtr m_model;

protected:
    virtual void Draw(const Point& point) = 0;
    virtual void Draw(const Line& point) = 0;
    virtual void Draw(const Circle& point) = 0;
    virtual void Draw(const Rectangle& point) = 0;

    void Draw(const Graphics& g) {}

public:
    explicit GraphicsDocumentView(const GraphicsDocumentPtr& model)
            :m_model(model) {}
    void Draw() {
        for( const auto & graphics : *(m_model->GetData()) ) {
            Draw(*graphics.second.get());
        }
    }

    void SetModel(GraphicsDocumentPtr& model) {
        m_model = model;
    }
};
using GraphicsDocumentViewPtr = std::shared_ptr<GraphicsDocumentView>;


#endif //HW05_GRAPHICEDITOR_GRAPHICSVIEW_H
