#ifndef HW05_GRAPHICEDITOR_GRAPHICSVIEW_H
#define HW05_GRAPHICEDITOR_GRAPHICSVIEW_H

#include "GraphicsModel.h"

class GraphicsDocumentView {   //View
private:
    GraphicsDocumentPtr m_model;
public:
    explicit GraphicsDocumentView(const GraphicsDocumentPtr& model)
            :m_model(model) {}
    void Draw() {
        for( const auto & graphics : *(m_model->GetData()) ) {
            graphics.second->GetData();     /// Что будет если передавать в GetData this.
                                            /// Чтобы под конкрутную отрисовку отдавались свои данные.
                                            /// Тогда модели придется знать что то о View что не есть хорошо
        }
    }
};
using GraphicsDocumentViewPtr = std::shared_ptr<GraphicsDocumentView>;


#endif //HW05_GRAPHICEDITOR_GRAPHICSVIEW_H
