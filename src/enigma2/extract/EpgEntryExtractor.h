#pragma once

#include <memory>
#include <string>
#include <vector>

#include "IExtractor.h"

namespace enigma2
{
  namespace extract
  {
    static const std::string GENRE_DIR = "/genres";
    static const std::string GENRE_ADDON_DATA_BASE_DIR = "special://userdata/addon_data/pvr.vuplus" + GENRE_DIR;

    class EpgEntryExtractor
      : public IExtractor
    {
    public:
      EpgEntryExtractor();
      ~EpgEntryExtractor(void);

      void ExtractFromEntry(enigma2::data::BaseEntry &entry);
      bool IsEnabled();

    private:
      std::vector<std::unique_ptr<IExtractor>> m_extractors;  
      bool m_anyExtractorEnabled;
    };
  } //namespace extract
} //namespace enigma2