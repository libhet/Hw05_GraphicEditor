#ifndef HW05_GRAPHICEDITOR_IEXPORT_H
#define HW05_GRAPHICEDITOR_IEXPORT_H

#include <string>
#include "graphics_types.h"
#include <iostream>


class IExport {
private:
    std::ostream* m_ostream;

protected:
    virtual GraphicsData ExportPoint(const PointPtr& data) = 0;
    virtual GraphicsData ExportLine(const LinePtr& data) = 0;
    virtual GraphicsData ExportCircle(const CirclePtr& data) = 0;
    virtual GraphicsData ExportRectangle(const RectanglePtr& data) = 0;

public:
    void SavePoint(const GraphicsData& data) {
        *m_ostream << data;
    }
    void SaveLine(const GraphicsData& data) {
        *m_ostream << data;
    }
    void SaveCircle(const GraphicsData& data) {
        *m_ostream << data;
    }
    void SaveRectangle(const GraphicsData& data) {
        *m_ostream << data;
    }
};


#endif //HW05_GRAPHICEDITOR_IEXPORT_H
