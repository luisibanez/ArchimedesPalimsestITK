/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include "QuickView.h"
#include "itkImageFileReader.h"

int main( int argc, char * argv [] )
{
  if( argc < 2 )
    {
    std::cerr << "Missing parameters" << std::endl;
    std::cerr << "Usage: " << argv[0] << " inputImageFileName " << std::endl;
    return EXIT_FAILURE;
    }

  std::string inputImageFileName = argv[1];

  const unsigned int ImageDimension = 2;
  typedef unsigned char PixelType;

  typedef itk::Image< PixelType, ImageDimension > ImageType;
  typedef itk::ImageFileReader< ImageType > ReaderType;

  ReaderType::Pointer reader  = ReaderType::New();
  reader->SetFileName( inputImageFileName );

  try
    {
    reader->Update();
    }
  catch( itk::ExceptionObject & except )
    {
    std::cerr << except << std::endl;
    return EXIT_FAILURE;
    }

  QuickView viewer;

  viewer.AddImage(reader->GetOutput(), true, inputImageFileName);
  viewer.Visualize(true);

  return EXIT_SUCCESS;
}
