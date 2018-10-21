#ifndef HW05_GRAPHICEDITOR_EXPORT_MY_FORMAT_H
#define HW05_GRAPHICEDITOR_EXPORT_MY_FORMAT_H

#include "../graphics_export.h"

class my_format_export : public IExport {
public:
protected:
    GraphicsData ExportPoint(const Point &data) const override;

    GraphicsData ExportLine(const Line &data) const override;

    GraphicsData ExportCircle(const Circle &data) const override;

    GraphicsData ExportRectangle(const Rectangle &data) const override;
};


#endif //HW05_GRAPHICEDITOR_EXPORT_MY_FORMAT_H
