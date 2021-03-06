//========================================================================================
//  
//  $File: $
//  
//  Owner: Kinanu
//  
//  $Author: $
//  
//  $DateTime: $
//  
//  $Revision: $
//  
//  $Change: $
//  
//  Copyright 1997-2012 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#include "VCPlugInHeaders.h"

// Interface includes:
#include "IAppearanceItemFacade.h"
#include "Utils.h"

// General includes:
#include "LIBSuiteCSB.h"

// Project includes:
#include "IHyperlinkSuite.h"
#include "LIBID.h"
#include "LIBHyperlinkUtils.h"

/** Check if a hyperlink can be applied to this selection
 @return kSucces when a hyperlink can be applied, kFalse otherwise
 */
bool16 LIBSuiteCSB::CanApplyLink(void)
{
    UIDList items = GetTarget();
    
    if(items != nil && items.Length() == 1)
    {
//        UIDRef itemUIDRef = items.GetRef(0);
//        
//        Utils<Facade::IAppearanceItemFacade> iAppearance;
//        
//        if(iAppearance->GetNumStates(itemUIDRef) > 1)
//        {
//            return kTrue;
//        }
        
        return kTrue;
    }
    
    return kFalse;
}

/** Performs apply link on the selection returning an ErrorCode.
 @return kSuccess on success, or an appropriate ErrorCode on failure. */
ErrorCode LIBSuiteCSB::ApplyLink(const IDocument* document, const PMString& url, const UID sourceUID)
{
    ErrorCode result = kFailure;
    UIDList items = GetTarget();
    
    if(items != nil && items.Length() == 1)
    {
        LIBHyperlinkUtils hyperlinkUtils(document);
        result = hyperlinkUtils.CreateHyperlink(items.GetRef(0), url, sourceUID);
    }
    
    return result;
}

ErrorCode LIBSuiteCSB::GetLink(IDocument* document, UID sourceUID, PMString& url)
{
    ErrorCode result = kFailure;
    LIBHyperlinkUtils hyperlinkUtils(document);
    
    result = hyperlinkUtils.GetHyperlink(sourceUID, url);
    
    return result;
}