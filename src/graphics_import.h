#ifndef HW05_GRAPHICEDITOR_IIMPORT_H
#define HW05_GRAPHICEDITOR_IIMPORT_H

#include <string>

#include "graphics_types.h"
#include "graphics_model.h"

//using GraphicsData = std::string;

class IImport {
private:
    GraphicsDocumentPtr m_model;
protected:
    virtual Point       ImportPoint(const GraphicsData& data) const = 0;
    virtual Line        ImportLine(const GraphicsData& data) const = 0;
    virtual Circle      ImportCircle(const GraphicsData& data) const = 0;
    virtual Rectangle   ImportRectangle(const GraphicsData& data) const = 0;

public:
    explicit IImport(GraphicsDocumentPtr& model) : m_model{model} {}
    virtual ~IImport()= default;

    void    AddPoint(const GraphicsData& data) const {

    }
    void    AddLine(const GraphicsData& data) const {
        m_model->AddLine(ImportLine(data));
    }
    void    AddCircle(const GraphicsData& data) const {
        m_model->AddCircle(ImportCircle(data));
    }
    void    AddRectangle(const GraphicsData& data) const {
        m_model->AddRectangle(ImportRectangle(data));
    }
};


#endif //HW05_GRAPHICEDITOR_IIMPORT_H
