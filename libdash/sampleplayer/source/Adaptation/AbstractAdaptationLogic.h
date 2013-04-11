/*
 * AbstractAdaptationLogic.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef SAMPLEPLAYER_ADAPTATION_ABSTRACTADAPTATIONLOGIC_H_
#define SAMPLEPLAYER_ADAPTATION_ABSTRACTADAPTATIONLOGIC_H_

#include "../Input/MediaObject.h"
#include "IAdaptationLogic.h"

namespace sampleplayer
{
    namespace adaptation
    {
        class AbstractAdaptationLogic : public IAdaptationLogic
        {
            public:
                AbstractAdaptationLogic             (dash::mpd::IPeriod* period, dash::mpd::IAdaptationSet *adaptationSet, dash::mpd::IMPD *mpd, uint32_t bufferSize);
                virtual ~AbstractAdaptationLogic    ();

                virtual uint32_t                    GetPosition         ();
                virtual void                        SetPosition         (uint32_t segmentNumber);
                virtual void                        SetRepresentation   (dash::mpd::IPeriod *period,
                                                                         dash::mpd::IAdaptationSet *adaptationSet,
                                                                         dash::mpd::IRepresentation *representation);

                virtual dash::mpd::IRepresentation* GetRepresentation   ()  = 0;
                virtual input::MediaObject*         GetSegment          ()  = 0;
                virtual input::MediaObject*         GetInitSegment      ()  = 0;
                virtual LogicType                   GetType             ()  = 0;

            protected:
                uint32_t    segmentOffset;
                uint32_t    bufferSize;
        };
    }
}
#endif /* LIBDASH_FRAMEWORK_ADAPTATION_ABSTRACTADAPTATIONLOGIC_H_ */
