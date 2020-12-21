//
//  CurrencyRecognizer.h
//  CardRecognizer
//
//  Created by Vladimir Tchernitski on 08/02/16.
//  Copyright © 2016 Vladimir Tchernitski. All rights reserved.
//

#ifndef CurrencyRecognizer_h
#define CurrencyRecognizer_h

#include "ICurrencyRecognizer.h"
#include <fstream>

class INeuralNetworkResultList;
class IServiceContainer;
class INeuralNetwork;
class INeuralNetworkObjectFactory;
class IRecognitionCoreDelegate;

class CCurrencyRecognizer : public ICurrencyRecognizer
{

public:
    CCurrencyRecognizer(const shared_ptr<IServiceContainer>& container);

    virtual ~CCurrencyRecognizer();

public:

    virtual shared_ptr<INeuralNetworkResultList> Process(cv::Mat& matrix,
                                                         vector<cv::Mat>& digitsSamples, std::string& postprocessedCurrency);

    virtual bool Deploy();

    virtual void SetRecognitionMode(PayCardsRecognizerMode flag);

    virtual void SetDelegate(const shared_ptr<IRecognitionCoreDelegate>& delegate);

    virtual void SetPathCurrencyYLocalizationViola(const string& path);

    virtual void SetPathCurrencyLocalizationXModel(const string& path);
    virtual void SetPathCurrencyLocalizationXStruct(const string& path);

    virtual void SetPathCurrencySpaceCharModel(const string& path);
    virtual void SetPathCurrencySpaceCharStruct(const string& path);

    virtual void SetPathCurrencyListTxt(const string& path);

private:

    void Predict(const vector<cv::Mat>& matrixes, shared_ptr<INeuralNetworkResultList>& neuralNetworkResultList, const shared_ptr<INeuralNetwork>& neuralNetwork);
    int FilterCoords(const std::vector<float>& xCoords, float modelDist, std::pair<int, int>& result);
    int LevenshteinDistance(const string& src, const string& dst);
private:

    weak_ptr<IServiceContainer> _container;
    weak_ptr<IRecognitionCoreDelegate> _delegate;
    weak_ptr<INeuralNetworkObjectFactory> _factory;

    string _pathCurrencyYLocalizationViola;

    cv::CascadeClassifier _yCascade;

    shared_ptr<INeuralNetwork> _localizationXNeuralNetwork;
    shared_ptr<INeuralNetwork> _spaceCharNeuralNetwork;

    string _pathCurrencyLocalizationXModel;
    string _pathCurrencyLocalizationXStruct;

    string _pathCurrencySpaceCharModel;
    string _pathCurrencySpaceCharStruct;
    string _pathCurrencyDictPath;
    std::istringstream _currenciesDict;

    PayCardsRecognizerMode _mode;
};


#endif /* CurrencyRecognizer_h */
