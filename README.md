# Comparative Analysis of AI Models for Detecting Online Gambling Promotion

## Repository for Research Paper Submission to ICoABCD 2025

**Authors:** Bryan Santosa, Risya Safira, Aliyah Jasmine Saliano

This repository contains all source files, datasets, and model artifacts used in the research paper titled **"Comparative Analysis of AI Models for Detecting Online Gambling Promotion from Trending YouTube Shorts’ Comments in Indonesia"**, which has been **accepted for presentation at ICoABCD 2025**.

---

## 📌 Overview

Online gambling promotion is increasingly prevalent in comment sections of social media platforms, including **YouTube Shorts**, which often lack robust moderation mechanisms. This research aims to compare multiple AI-based approaches to detect such harmful content effectively.

We evaluate and compare the performance of different machine learning and deep learning models on a curated dataset of YouTube Shorts comments. This repository ensures full transparency and reproducibility of the experimental pipeline.

---

## 📂 Repository Structure

```
├── dataset/
│   ├── raw/               # Raw scraped comments
│   ├── processed/         # Cleaned and labeled dataset
│   └── kaggle_link.txt    # Direct link to Kaggle dataset
│
├── preprocessing/
│   └── preprocessing.ipynb         # Text cleaning, labeling, and dataset preparation
│
├── training/
│   ├── model1_training.ipynb       # Training scripts for baseline ML models
│   ├── model2_training.ipynb       # Training scripts for deep learning models
│   └── ...
│
├── evaluation/
│   ├── evaluation.ipynb            # Accuracy, F1-score, precision, recall, confusion matrices
│
└── models/
    ├── model1_params.pkl           # Saved ML model parameters
    ├── model2_weights.h5           # Neural network weights
    └── ...
```

---

## 📘 Dataset Information

The dataset used in this research was created by **scraping comments from trending YouTube Shorts in Indonesia**. Each comment was manually inspected and labeled as either containing online gambling promotion or not.

You can also access the dataset publicly on Kaggle:
**Kaggle Dataset:** [https://www.kaggle.com/datasets/bukanbryan/online-gambling-promotions-in-trending-shorts](https://www.kaggle.com/datasets/bukanbryan/online-gambling-promotions-in-trending-shorts)

Dataset includes:

* The shorts sources of the comments dataset
* Preprocessed and cleaned comments
* Labeled preprocessed comments
* Comments with indobert embeddings 

---

## 🧠 Models Compared

The following models were trained and evaluated:

* Random Forest
* Bernoulli Naïve Bayes
* IndoBERT
* RoBERTa

Each model is trained using the corresponding notebook under `training/` and evaluated using a standardized pipeline.

---

## 📊 Evaluation Metrics

Model performance is assessed using:

* **Accuracy**
* **Weighted Precision**
* **Weighted Recall**
* **Weighted F1-score**
* **Confusion Matrix**

These metrics allow a robust comparison across traditional ML models and deep learning approaches.

## 📄 Paper Status

* **Title:** Comparative Analysis of AI Models for Detecting Online Gambling Promotion from Trending YouTube Shorts’ Comments in Indonesia
* **Conference:** ICoABCD 2025
* **Status:** *Accepted (Not yet published)*

A link to the published version will be added once available.

---

## 🤝 Acknowledgments

This research was made possible through the contributions of Bryan Santosa, who led the methodology design, coding and training of deep leaning models, prepared the dataset from scratch, implemented Mistral labeling and contributed on the writing of the Literature Review, Methodology, and quality checking of the final product; Risya Safira, who led the writing of the Introduction and the training of BERT models, while also contributing to the writing of Literature Review, Methodology, Results and discussion  , and conclussion; and Aliyah Jasmine Saliano, who led the other half of the BERT model training, and writing of the conclussion and discussion while also contributed to the writing of all parts of the research paper including quality checking of the final draft. Special thanks are given to Shania Priccilia and Diana for their supervision, validation, project administration, and academic advising throughout this research and paper preparation

---

## 📬 Contact

For questions or collaboration inquiries, feel free to reach out:

* **Bryan Santosa** – [bryan98market@gmail.com](mailto:bryan98market@gmail.com) - GitHub : OhMyBreee
* **Risya Safira** - [risyasfr@gmail.com](mailto:risyasfr@gmail.com)
* **Aliyah Jasmine Saliano** - [aliyahjasmine05@gmail.com](mailto:aliyahjasmine05@gmail.com)

---

If you use this dataset or code, please cite our upcoming paper once published.
