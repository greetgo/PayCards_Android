//
//  ICurrencyRecognizer.h
//  CardRecognizer
//
//  Created by Vladimir Tchernitski on 08/02/16.
//  Copyright © 2016 Vladimir Tchernitski. All rights reserved.
//

#ifndef ICurrencyRecognizer_h
#define ICurrencyRecognizer_h

#include "IBaseObj.h"
#include "Enums.h"

class INeuralNetworkResultList;
class IRecognitionCoreDelegate;

using namespace std;

class ICurrencyRecognizer : public IBaseObj
{
public:

    virtual ~ICurrencyRecognizer() {}

public:

    virtual shared_ptr<INeuralNetworkResultList> Process(cv::Mat& frame, vector<cv::Mat>& samples, std::string& postprocessedCurrency) = 0;
    virtual bool Deploy() = 0;

    virtual void SetRecognitionMode(PayCardsRecognizerMode flag) = 0;

    virtual void SetDelegate(const shared_ptr<IRecognitionCoreDelegate>& delegate) = 0;

    virtual void SetPathCurrencyYLocalizationViola(const string& path) = 0;

    virtual void SetPathCurrencyLocalizationXModel(const string& path) = 0;
    virtual void SetPathCurrencyLocalizationXStruct(const string& path) = 0;

    virtual void SetPathCurrencySpaceCharModel(const string& path) = 0;
    virtual void SetPathCurrencySpaceCharStruct(const string& path) = 0;

    virtual void SetPathCurrencyListTxt(const string& path) = 0;

};


#endif /* ICurrencyRecognizer_h */
