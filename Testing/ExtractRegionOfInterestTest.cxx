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

#include "itkRGBPixel.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkRegionOfInterestImageFilter.h"
#include "itkImage.h"

int ExtractRegionOfInterestTest( int argc, char * argv [] )
{

  if( argc < 7 )
    {
    std::cerr << "Usage: " << std::endl;
    std::cerr << argv[0] << " inputImageFile startX startY sizeX sizeY outputImageFile " << std::endl;
    return EXIT_FAILURE;
    }

  typedef itk::RGBPixel< unsigned char >      PixelType;
  const   unsigned int                        Dimension = 2;
  typedef itk::Image< PixelType, Dimension >  ImageType;

  typedef itk::ImageFileReader< ImageType >  ReaderType;
  typedef itk::ImageFileWriter< ImageType >  WriterType;

  ReaderType::Pointer reader = ReaderType::New();
  WriterType::Pointer writer = WriterType::New();

  const char * inputFilename  = argv[1];
  const char * outputFilename = argv[6];

  reader->SetFileName( inputFilename  );
  writer->SetFileName( outputFilename );

  typedef itk::RegionOfInterestImageFilter< ImageType, ImageType > RegionFilterType;
  RegionFilterType::Pointer regionFilter = RegionFilterType::New();

  ImageType::IndexType index;
  index[0] = atoi( argv[2] );
  index[1] = atoi( argv[3] );

  ImageType::SizeType size;
  size[0] = atoi( argv[4] );
  size[1] = atoi( argv[5] );

  ImageType::RegionType region;
  region.SetIndex( index );
  region.SetSize( size );

  regionFilter->SetRegionOfInterest( region );

  regionFilter->SetInput( reader->GetOutput() );
  writer->SetInput( regionFilter->GetOutput() );

  try
    {
    writer->Update();
    }
  catch( itk::ExceptionObject & err )
    {
    std::cerr << "ExceptionObject caught !" << std::endl;
    std::cerr << err << std::endl;
    return EXIT_FAILURE;
    }

  const ImageType * image = reader->GetOutput();

  image->Print( std::cout );

  return EXIT_SUCCESS;
}
