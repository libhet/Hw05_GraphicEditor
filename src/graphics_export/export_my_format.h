#ifndef HW05_GRAPHICEDITOR_EXPORT_MY_FORMAT_H
#define HW05_GRAPHICEDITOR_EXPORT_MY_FORMAT_H

#include "../graphics_export.h"

class my_format_export : public IExport {
public:
    void ExportPoint(const GraphicsData &data) override;

    void ExportLine(const GraphicsData &data) override;

    void ExportCircle(const GraphicsData &data) override;

    void ExportRectangle(const GraphicsData &data) override;
};


#endif //HW05_GRAPHICEDITOR_EXPORT_MY_FORMAT_H
