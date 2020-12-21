//
//  RecognitionResult.cpp
//  CardRecognizer
//
//  Created by Vladimir Tchernitski on 11/01/16.
//  Copyright © 2016 Vladimir Tchernitski. All rights reserved.
//

#include "RecognitionResult.h"
#include "INeuralNetworkResultList.h"

CRecognitionResult::CRecognitionResult() : _recognitionStatus(RecognitionStatusIdle),
                                           _postprocessedName(""), _postprocessedCurrency("") {
}

CRecognitionResult::~CRecognitionResult() {
    Reset();
}

void CRecognitionResult::Reset() {
    _postprocessedName = "";
    _numberResult = nullptr;
    _dateResult = nullptr;
    _nameResult = nullptr;
    _currencyResult = nullptr;

    _cardImage.release();
    _recognitionStatus = RecognitionStatusIdle;
}

shared_ptr<INeuralNetworkResultList> CRecognitionResult::GetNumberResult() const {
    return _numberResult;
}

shared_ptr<INeuralNetworkResultList> CRecognitionResult::GetDateResult() const {
    return _dateResult;
}

shared_ptr<INeuralNetworkResultList> CRecognitionResult::GetNameResult() const {
    return _nameResult;
}

shared_ptr<INeuralNetworkResultList> CRecognitionResult::GetCurrencyResult() const {
    return _currencyResult;
}

RecognitionStatus CRecognitionResult::GetRecognitionStatus() const {
    return _recognitionStatus;
}

cv::Mat CRecognitionResult::GetCardImage() const {
    return _cardImage;
}

cv::Rect CRecognitionResult::GetNumberRect() const {
    return _numberRect;
}

cv::Rect CRecognitionResult::GetDateRect() const {
    return _dateRect;
}

std::string CRecognitionResult::GetPostprocessedName() const {
    return _postprocessedName;
}

std::string CRecognitionResult::GetPostprocessedCurrency() const {
    return _postprocessedCurrency;
}

void CRecognitionResult::SetNumberResult(shared_ptr<INeuralNetworkResultList> result) {
    _numberResult = result;
    SetRecognitionStatus(RecognitionStatusNumber);
}

void CRecognitionResult::SetDateResult(shared_ptr<INeuralNetworkResultList> result) {
    _dateResult = result;
    SetRecognitionStatus(RecognitionStatusDate);
}

void CRecognitionResult::SetNameResult(shared_ptr<INeuralNetworkResultList> result) {
    _nameResult = result;
    SetRecognitionStatus(RecognitionStatusName);
}

void CRecognitionResult::SetCurrencyResult(shared_ptr<INeuralNetworkResultList> result) {
    _currencyResult = result;
    SetRecognitionStatus(RecognitionStatusCurrency);
}

void CRecognitionResult::SetRecognitionStatus(RecognitionStatus status) {
    _recognitionStatus = status;
}

void CRecognitionResult::SetCardImage(cv::Mat cardImage) {
    _cardImage = cardImage;
}

void CRecognitionResult::SetNumberRect(cv::Rect numberRect) {
    _numberRect = numberRect;
}

void CRecognitionResult::SetDateRect(cv::Rect dateRect) {
    _dateRect = dateRect;
}

void CRecognitionResult::SetPostprocessedName(std::string name) {
    _postprocessedName = name;
}


void CRecognitionResult::SetPostprocessedCurrency(std::string currency) {
    _postprocessedCurrency = currency;
}
