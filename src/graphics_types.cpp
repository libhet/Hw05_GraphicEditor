//
// Created by cooki on 21.10.2018.
//

#include "graphics_export.h"
#include "graphics_import.h"
#include "graphics_types.h"

void Point::LoadData(const IImport& loader, const GraphicsData& data) override
{
    loader.AddPoint(data);
}

GraphicsData Point::SaveData(const IExport &exporter) {
    return nullptr;
}

void Line::LoadData(const IImport &loader, const GraphicsData &data) {
    loader.AddLine(data);
}

GraphicsData Line::SaveData(const IExport &exporter) {
    return exporter;
}
